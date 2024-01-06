class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> grid(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>>q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[4] = {0, 0, -1, 1};
            int dc[4] = {-1, 1, 0, 0};
            
            for(int i =0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];

                if(rr >= 0 && rr < row && cc >= 0 && cc < col && grid[rr][cc] > 1 + grid[r][c]){
                    grid[rr][cc] = 1 + grid[r][c];
                    q.push({rr, cc});
                }
            }
        }
        return grid;
    }
};