class Solution {
private:
    bool solve(vector<int>& nums,int s, int e, int n){
        int p = 0;
        for(int i =0; i < n ; i++){
            if(i <= e && i >= s){
                continue;
            }
            if(nums[i] <= p)
                return false;

            p = nums[i];
        }
        return true;
    }
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt = 0; 
        int n = nums.size();
        for(int i =0; i < n ; i++){
            for(int j = i; j < n ; j++){
                if(solve(nums, i , j, n)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};