class Solution {
private:
    void solve(int idx, int sum, int n, vector<vector<int>>& res, vector<int>& ans, int k ){
        if(sum == n && k == 0){
            res.push_back(ans);
            return;
        }

        if(sum > n){
            return;
        }

        for(int i = idx; i<=9; i++){
            if(i > n){
                break;
            }
            ans.push_back(i);
            solve(i + 1, sum + i,n, res, ans, k - 1);
            ans.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> res;
        solve(1, 0, n, res, ans, k);
        return res;
    }
};