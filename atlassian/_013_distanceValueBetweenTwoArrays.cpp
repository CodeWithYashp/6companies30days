class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res  = 0;
        for(int i =0; i < arr1.size(); i++){
            int n = 0;
            for(int j =0; j < arr2.size(); j++){
                arr1[i] - arr2[j];
                if(abs(arr1[i] - arr2[j]) <= d){
                    n = 1;
                    break;
                }
            }

            if(n == 0){
                res++;
            }
        }
        return res;
    }
};