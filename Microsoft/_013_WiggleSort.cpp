class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res(n);
        int i = 1;
        int j = n - 1;
        while(i < n){
            res[i] = nums[j--];
            i+=2;
        }
        i = 0;
        while( i < n){
            res[i] = nums[j--];
            i+=2;
        }
        for(int i =0; i < n; i++){
            nums[i] = res[i];
        }
    }
};