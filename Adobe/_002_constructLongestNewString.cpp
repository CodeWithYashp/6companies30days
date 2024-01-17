class Solution {
public:
    int longestString(int x, int y, int z) {
        string res = "";
        for(int i = 0; i < z; i++){
            res += "AB";
        }

        int mini = min(x, y);
        
        for(int i = 0; i < mini; i++){
            res += "AA";
            res += "BB";
            x--;
            y--;
        }

        if(x != 0)  res += "AA";
        if(y != 0)  res += "BB";

        return res.size();
    }
};