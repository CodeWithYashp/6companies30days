class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        if (n < 10) {
            return res;
        }

        unordered_map<string, int> freq;
        for (int i = 0; i <= n - 10; i++) {
            string dna = s.substr(i, 10);
            freq[dna]++;
        }

        for (const auto& it : freq) {
            if (it.second > 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};