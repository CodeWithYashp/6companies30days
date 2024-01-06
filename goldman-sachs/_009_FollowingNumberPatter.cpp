class Solution{   
public:
    string printMinNumberForPattern(string S){
        string res= "";
        stack<int> ans;
        
        int n = S.size();
        
        for(int i = 0; i <= n; i++){
            ans.push(i+1);
            
            if(S[i] == 'I' || i == n){
                while(!ans.empty()){
                    res += to_string(ans.top());
                    ans.pop();
                }
            }
        }
        return res;
    }
};