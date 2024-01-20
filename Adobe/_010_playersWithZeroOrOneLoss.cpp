class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> res(2);

        unordered_map<int, int> win;
        unordered_map<int, int> lose;

        for(int i = 0; i < matches.size(); i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }

        for(auto it : win){
            if(lose.find(it.first) == lose.end())
                res[0].push_back(it.first);
        }

        for(auto it : lose){
            if(it.second == 1) 
                res[1].push_back(it.first);
        }

        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};