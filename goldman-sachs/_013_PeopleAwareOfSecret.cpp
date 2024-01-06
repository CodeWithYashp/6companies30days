class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n + 1, 0);
        const long long mod = 1e9 + 7;
        long long noOfPeopleSharingSecret = 0;
        long long ans = 0;
        
        dp[1] = 1;
        
        for (int day = 2; day <= n; day++) {
            long long noOfNewPeopleSharingSecret = dp[max(day - delay, 0)];
            long long noOfPeopleForgettingSecret = dp[max(day - forget, 0)];
            noOfPeopleSharingSecret +=  (noOfNewPeopleSharingSecret - noOfPeopleForgettingSecret + mod) % mod;
            dp[day] = noOfPeopleSharingSecret;
        }

        for (int i = n - forget + 1; i <= n; i++) {
            ans = (ans + dp[i]) % mod;
        }

        return static_cast<int>(ans);
    }
};