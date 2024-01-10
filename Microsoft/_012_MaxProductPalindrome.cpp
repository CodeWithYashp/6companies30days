class Solution {
private:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

public:
    int maxProduct(string s) {
        int n = s.length();
        int maxProduct = 0;

        for (int mask = 1; mask < (1 << n) - 1; mask++) {
            string x = "", y = "";
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    x += s[i];
                } else {
                    y += s[i];
                }
            }

            int product = longestPalindromeSubseq(x) * longestPalindromeSubseq(y);
            maxProduct = max(maxProduct, product);
        }

        return maxProduct;
    }
};