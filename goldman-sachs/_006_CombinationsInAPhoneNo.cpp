class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char, string>digitsToChar = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        function<void(int, string)> backtrack = [&](int i, string curstr) {
            if (curstr.length() == digits.length()) {
                res.push_back(curstr);
                return;
            }
            for (char c : digitsToChar[digits[i]]) {
                backtrack(i+1, curstr + c);
            }
        };
    
        if (!digits.empty()) {
            backtrack(0, "");
        }
    
        return res;
    }
};