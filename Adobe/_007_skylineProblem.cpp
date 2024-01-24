class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> cords;
        vector<vector<int>>res;

        for(auto a: buildings){
            cords.push_back({a[0],-1*a[2]});
            cords.push_back({a[1],a[2]});
        }


        sort(cords.begin(), cords.end());
        multiset<int,greater<int>> pq;

        pq.insert(0);
        int prev = 0;

        for(auto &it : cords){
            int val = it.first;
            int height = it.second;

            height < 0 ? pq.insert(-height) : pq.erase(pq.find(height));

            int top = *pq.begin();

            if(prev != top) {
                res.push_back({val, top});
                prev = top;
            }
        }
        return res;
    }
};