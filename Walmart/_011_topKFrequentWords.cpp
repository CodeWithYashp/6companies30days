class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i =0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        vector<pair<string, int>> temp;

        for(auto m : mp){
            temp.push_back(m);
        }

        auto compare = [&](auto &a, auto &b){
            if(a.second == b.second){
                return a.first < b.first;
            }else{
                return a.second > b.second;
            }
        };

        sort(temp.begin(), temp.end(), compare);

        for( auto i : temp){
            ans.push_back(i.first);
            k--;
            if(k == 0){
                break;
            }
        }
        
        return ans;
    }
};