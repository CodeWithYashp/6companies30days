class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& end, vector<vector<int>>& vec) {
        vector<vector<int>> req;

        for(int i=0;i<vec.size();i++){
            int val=abs(vec[i][0]- vec[i][2])+abs(vec[i][1]-vec[i][3]);
            if(val>vec[i][4]){
                req.push_back(vec[i]);
            }
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        map<pair<int,int>,int> mp;
        int x=start[0];
        int y=start[1];
        mp[make_pair(x,y)]=0;

        for(int i=0;i<req.size();i++){
            int val=abs(x-req[i][0])+abs(y-req[i][1]);
            int net_val=val+req[i][4];
            if(mp.count(make_pair(req[i][0],req[i][1])) && mp[make_pair(req[i][0],req[i][1])]>val){
                mp[make_pair(req[i][0],req[i][1])]=val;
            }
            else if(!mp.count(make_pair(req[i][0],req[i][1]))){
                mp[make_pair(req[i][0],req[i][1])]=val;
            }
            if(mp.count(make_pair(req[i][2],req[i][3])) && mp[make_pair(req[i][2],req[i][3])]>net_val){
                mp[make_pair(req[i][2],req[i][3])]=net_val;
            }
            else if(!mp.count(make_pair(req[i][2],req[i][3]))){
                mp[make_pair(req[i][2],req[i][3])]=net_val;
            }            
            pq.push({net_val,req[i][0],req[i][1],req[i][2],req[i][3]});
        }

        while(!pq.empty()){
            vector<int> temp=pq.top();
            pq.pop();
            for(int i=0;i<req.size();i++){
                int val=temp[0]+abs(temp[3]-req[i][0])+abs(temp[4]-req[i][1]);
                if(mp[make_pair(req[i][0],req[i][1])]>val){
                    mp[make_pair(req[i][0],req[i][1])]=val;
                }
                int net_val=req[i][4]+val;
                if(mp[make_pair(req[i][2],req[i][3])]>net_val){
                    mp[make_pair(req[i][2],req[i][3])]=net_val;
                    pq.push({net_val,req[i][0],req[i][1],req[i][2],req[i][3]});
                }
            }
        }

        int ans=abs(start[0]-end[0])+abs(start[1]-end[1]);

        for(auto it: mp){
            int val=it.second+abs(it.first.first-end[0])+abs(it.first.second-end[1]);
            ans=min(ans,val);
        }
        
        return ans;
    }
};