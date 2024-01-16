class Solution {
private:
    int dp[301];
    int solve(int i, string s, set<string> &words){
        if(i == s.size())
            return 1;
        string t;
        if(dp[i] != -1){
            return dp[i];
        }

        for(int j = i; j < s.size(); j++){
            t += s[j];
            if(words.find(t) != words.end()){
                if(solve(j + 1, s, words))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> words;
        memset(dp,-1,sizeof dp);
        for(auto i : wordDict){
            words.insert(i);
        }
        return solve(0, s, words);
    }
};