class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int ans = 0, window = 0, l = 0;
        for(int r = 0; r < n; r++){
            window += abs(s[r] - t[r]);
            while(window > maxCost){
                window -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};