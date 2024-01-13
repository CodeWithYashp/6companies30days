class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f0 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            f0 += i * nums[i];
        }

        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int size = nums.size();
        int max_fn = f0;
        int prev_fn = f0;

        for (int i = size - 1; i > 0; --i) {
            int num = nums[i];
            int next_fn = prev_fn + total_sum - size * num;
            max_fn = max(max_fn, next_fn);

            prev_fn = next_fn;
        }

        return max_fn;
    }
};