class Solution {
public:

    bool isValid(vector<int> & times){
        for(int i = 0; i<times.size() - 2; i++){
            if(times[i+2] - times[i]<60)
            return true;
        }
        return false;
    }


    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string, vector<int>>v; 
        for(auto i : access_times){
            string hours = i[1].substr(0,2);
            string min = i[1].substr(2,2);
            int totalMin = stoi(hours)*60+stoi(min);
            v[i[0]].push_back(totalMin);
        }
        // for each employee
        for(auto i:v){
            if(i.second.size()<3){
                continue;
            }
            sort(i.second.begin(), i.second.end());
            if(isValid(i.second)){
                ans.push_back(i.first); 
           }
        }
        return ans;
    }
};