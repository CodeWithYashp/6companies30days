class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Check if the envelopes are empty
        if (envelopes.empty()) {
            return 0;
        }

        // Sort envelopes based on width in ascending order and height in descending order
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        // Vector to store the heights of envelopes forming an increasing subsequence
        vector<int> dp;

        // Iterate through each envelope
        for (const auto& envelope : envelopes) {
            // Use binary search to find the position to insert the current envelope's height
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);

            // If the position is at the end, add a new element to the increasing subsequence
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                // If not, update the existing element in the subsequence
                *it = envelope[1];
            }
        }

        // The length of the increasing subsequence represents the answer
        return dp.size();
    }
};