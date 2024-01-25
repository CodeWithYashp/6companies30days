class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
        for(int i = 0; i < startWords.size(); i++){
            sort(startWords[i].begin(), startWords[i].end());
            st.insert(startWords[i]);
        }

        int res = 0;
        string s = "";
        string t = "";
        for(int i = 0; i < targetWords.size(); i++){
            s = targetWords[i];
            sort(s.begin(), s.end());
            for(int j = 0; j < s.length(); j++){
                t = s.substr(0,j)+s.substr(j+1);

                if(st.find(t)!=st.end())//substring found
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};