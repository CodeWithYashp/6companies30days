class Solution {
public:
    set<string> st;
    int dp[51][51];
    int solve(string &str, int s, int e){
        if(e >= str.length()){
            if(s == e){
                return 0;
            }
            return e - s + 1;
        }

        if(dp[s][e] != -1){
            return dp[s][e];
        }

        string temp = str.substr(s, e - s + 1);
        if(st.find(temp) != st.end()){
            return dp[s][e] = min(solve(str, s, e + 1), solve(str, e+1, e+1));
        }

        int m = temp.length();
        return dp[s][e] = min(solve(str,s,e+1),m+solve(str,e+1,e+1));
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        st.clear();
        int i = 0;
        memset(dp, -1, sizeof(dp));
        for(auto word : dictionary){
            st.insert(word);
        }
        return solve(s, 0, 0);
    }
};