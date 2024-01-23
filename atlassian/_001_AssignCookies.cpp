class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int cnt = 0;
        int m = s.size();
        int n = g.size();
        int i = 0, j = 0;

        while(i < n && j < m){
            if(g[i] <= s[j]){
                i++;
                j++;
                cnt++;
            }else if(g[i] > s[j]) j++; 
        }

        return cnt;
    }
};