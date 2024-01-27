class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int res = 0;

        for(int i = 0; i < n; i++){
            if(i + 1 < n && directions[i] == 'R' && directions[i + 1] == 'L'){
                res += 2;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
            if(i + 1 < n && directions[i] == 'R' && directions[i + 1] == 'S'){
                res += 1;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
            if(i + 1 < n && directions[i] == 'S' && directions[i + 1] == 'L'){
                res += 1;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(directions[i] == 'R' && directions[i + 1] == 'L'){
                res += 2;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
            if(directions[i] == 'S' && directions[i + 1] == 'L'){
                res += 1;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
            if(directions[i] == 'R' && directions[i + 1] == 'S'){
                res += 1;
                directions[i] = 'S';
                directions[i + 1] = 'S';
            }
            
        }
        return res;
    }
};