class Solution {
private:
    int solve(vector<int> v){
        int count1 = 1;
        for(int i = 1; i < v.size(); i++){
            int count = 1;
            bool b = false;
            while(i < v.size() && v[i] == v[i - 1] + 1){
                i++;
                b = true;
                count++;
            }
            if(b) i--;
            count1 = max(count1, count);
        }
        return count1;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int res;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int count1 = solve(hBars);
        int count2 = solve(vBars);
        res = min(count1, count2) + 1;

        return res*res;
    }
};