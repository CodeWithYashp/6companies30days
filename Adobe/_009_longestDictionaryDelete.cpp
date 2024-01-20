class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
       string ans = "";
       int size = 0;
       int n = s.size();

       for(auto it: dictionary){
           string a = it;
           int i = 0, j = 0;
           int m = a.size();
           int cnt = 0;
           while(i < n && j < m){
               if(s[i] == a[j]){
                   i++;
                   j++;
                   cnt++;
               }else{
                   i++;
               }
           } 
           if(size < cnt && j == m){
               ans = a;
               size = cnt;
           }else if(size == cnt && j == m){
               if(a < ans){
                   ans = a;
               }
           }
       }
       return ans;
    }
};