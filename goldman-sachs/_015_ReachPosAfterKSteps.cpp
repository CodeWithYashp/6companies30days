class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int rows = 3002;
        int cols = 3001;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        return solve(startPos, endPos, startPos, k, dp);
    }

private:
    int MOD = 1000000007;

    int solve(int s, int e, int curr, int k, vector<vector<int>> &dp) {
        if (k == 0) {
            if (curr == e) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[curr + 1001][k] != -1) {
            return dp[curr + 1001][k];
        }
        int moveR = solve(s, e, curr + 1, k - 1, dp);
        int moveL = solve(s, e, curr - 1, k - 1, dp);

        return dp[curr + 1001][k] = (moveR + moveL) % MOD;
    }
};
