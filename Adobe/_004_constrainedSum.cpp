class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;

        int ans = INT_MIN;

        for(int i  = 0; i < nums.size(); i++){
            int n = nums[i];
            int maxi = n + (!dq.empty() ? dq.front().second : 0);
            ans = max(ans, maxi);

            while(!dq.empty() && maxi >= dq.back().second){
                dq.pop_back();
            }

            if(maxi > 0){
                dq.push_back(make_pair(i, maxi));
            }

            if(!dq.empty() && dq.front().first == i - k){
                dq.pop_front();
            }
        }
        return ans;
    }
};