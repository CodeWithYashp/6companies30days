class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        if (envelopes.empty()) {
            return 0;
        }

        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        
        vector<int> dp;

        
        for (const auto& envelope : envelopes) {
            
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);

           
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                
                *it = envelope[1];
            }
        }

        
        return dp.size();
    }
};