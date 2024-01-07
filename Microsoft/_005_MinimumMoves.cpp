class Solution {
private:
    // void print(vector<int>& nums){
    //     for(int i = 0; i < nums.size(); i++){
    //         cout<<nums[i]<<" ";
    //     }cout<<endl;
    // }
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // print(nums);
        int n = nums.size();

        int mid = n % 2 == 0 ? (nums[n / 2] + nums[n / 2 - 1]) / 2 : nums[n/2];
        // cout<< "median is " << mid<<endl;
        int ans = 0;

        for(int num : nums){
            ans += abs(num - mid);
        // cout<< "for " << num <<" ans is" <<ans << endl;
        }

        return ans;
    }
};