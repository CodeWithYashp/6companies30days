class Solution {
private:
    vector<int> solve(string &s, string &a){
         vector<int> res;
        
        for(int i = 0; i < s.size(); i++) {
            if(s.substr(i, a.size()) == a)
                res.push_back(i);
        }
        
        return res;
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> v = solve(s, a);
        vector<int> w = solve(s, b);
        
        vector<int> ans;
        int i = 0;
        int j = 0;
        
        while(i < v.size() && j < w.size()) {
            if(abs(v[i] - w[j]) <= k) {
                ans.push_back(v[i]);
                i++;
            } else {
                if(v[i] < w[j])
                    i++;
                else
                    j++;
            }
        }
        
        return ans;
    }
};