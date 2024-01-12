class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int n = nums.size();
        for (int i = 0; i < k; i++){
            q.push({nums[i], i});
        }
        for (int i = k; i < n; i++){
            if (nums[i] > q.top().first){
                q.pop();
                q.push({nums[i], i});
            }
        }
        vector<pair<int, int>> res;
        while (q.size()){
            int v = q.top().first;
            int index = q.top().second;
            q.pop();
            res.push_back({index, v});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for (int i = 0; i < k; i++){
            ans.push_back(res[i].second);
        }
        return ans;
    }
};