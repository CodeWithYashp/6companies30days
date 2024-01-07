class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int a = img.size(); //rows
        int b = img[0].size(); //cols

        vector<vector<int>> ans(a, vector<int>(b, 0));

        int xIndexArr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int yIndexArr[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                int sum = 0;
                int cnt = 0;
                for(int k = 0; k < 9; k++){
                    int newXInd = i + xIndexArr[k];
                    int newYInd = j + yIndexArr[k];

                    if(newXInd >= 0 && newXInd < a && newYInd >= 0 && newYInd < b){
                        sum += img[newXInd][newYInd];
                        cnt++;
                    }
                }
                ans[i][j] = (sum / cnt);
            }
        }
        return ans;
    }
};