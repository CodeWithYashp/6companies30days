class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(arr[abs(arr[i]) - 1] < 0){
                ans.push_back(abs(arr[i]));
            }else {
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};