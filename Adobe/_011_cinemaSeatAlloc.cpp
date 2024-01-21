class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
        unordered_map<int, int> dp;
        for(auto i : nums){
            int row = i[0];
            int pos = i[1];
            dp[row] |= (1 << (pos - 1));
        }
        int res = 2 * ( n - dp.size());

        for(auto &[row, pos] : dp){
            if(!(pos & (0b0111111110))){
                res += 2;
            }
            else{
                if(!(pos&(0b0111100000)) || !(pos&(0b0001111000)) || !(pos&(0b0000011110))){
                    res++;
                }
            }
        }
        return res;
    }
};