class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        for(int i = 0; i < asteroids.size(); i++){
            if(mass >= asteroids[i]){
                mass += asteroids[i];
            }else{
                return false;
            }
            if(mass > 100000){
                return true;
            }
        }
        return true;
    }
};