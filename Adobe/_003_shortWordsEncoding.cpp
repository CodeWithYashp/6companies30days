class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> unique1(words.begin(), words.end());
        set<string> unique2(words.begin(), words.end());
        int ans = 0;
        for(auto word: unique1){
            for(int i = 1; i < word.size(); i++){
                unique2.erase(word.substr(i));
            }
        }
        for(auto word : unique2){
                ans += word.size() + 1;
            }
        return ans;
    }
};