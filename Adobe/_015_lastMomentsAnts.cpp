class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int t = 0;
        
        for(auto l: left)
            t = max(t, l);

        for(auto r: right)
            t = max(t, n - r);   

        return t;
    }
};