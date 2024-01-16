class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        string ans = "";
        for(auto ch : s){
            mp[ch]++;
        }

        vector<pair<int, int>>v;

        for(auto i : mp){
            pair<int, char> p;
            p = make_pair(i.second, i.first);
            v.push_back(p);
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        for(auto i : v){
            int a = i.first;
            for(int j = 0; j < a; j++){
                ans += i.second;
            }
        }
        return ans;
    }
};