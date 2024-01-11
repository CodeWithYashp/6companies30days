class Solution {
private:
  vector<int> res;
    // void solve(vector<int> &nums, int i, vector<int> curr, int p){
    //     if(curr.size() > res.size()){
    //         res = curr;
    //     }

    //     for(int j = i; j < nums.size(); j++){
    //         if(nums[j] % p == 0){
    //             curr.push_back(nums[j]);
    //             solve(nums, j + 1, curr, nums[j]);
    //             curr.pop_back();
    //         }
    //     }
    // }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> v(nums.size(), -1);

        int maxS = 1, maxI = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    v[i] = j;
                }
            }

            if (dp[i] > maxS) {
                maxS = dp[i];
                maxI = i;
            }
        }

        while (maxI != -1) {
            res.push_back(nums[maxI]);
            maxI = v[maxI];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};