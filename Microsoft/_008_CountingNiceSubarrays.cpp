class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
        }
        //find number of subarrays with sum == k.
        int s = 0; 
        int cnt =0;
        for(int i = 0; i < n; i++){
            s += nums[i];
            if(s == k){
                cnt++;
            }

            if(m.find(s - k) != m.end()){
                cnt += m[s - k];
            }
            m[s]++;
        }
        return cnt;
    }
};