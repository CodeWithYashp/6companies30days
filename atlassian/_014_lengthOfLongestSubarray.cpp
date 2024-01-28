class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int m = 0;
        int n = 0;
        int res = 0;
        while(n < nums.size()){
            mp[nums[n]]++;
            while(mp[nums[n]] > k){
                mp[nums[m]]--;
                m++;
            }
            res = max(res, n - m + 1);
            n++;
        }
        return res;
    }
};