class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                ans.push_back({i, j, abs(i - rCenter) + abs(j - cCenter)});
            }
        }

        sort(ans.begin(), ans.end(), [](vector<int> &col1,  vector<int>& col2){
            return col1[2] < col2[2];
        });

        for(vector<int> &it: ans){
            it.pop_back();
        }

        return ans;
    }
};