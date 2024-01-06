class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> st;

        int n = nums.size();
        for(int i = 0; i < n; ++i){
            for(int j =i; j < n; ++j){
                string s;
                int cnt = 0;
                for(int m = i; m <= j; ++m){
                    s.push_back(nums[m]);
                    if(nums[m] % p == 0)
                        cnt++;
                    if(cnt > k)
                        break;
                }
                if(cnt <= k){
                    st.insert(s);
                }
            }
        }

        return st.size();
    }
};