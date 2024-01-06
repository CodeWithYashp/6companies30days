string encode(string src)
{     
  string ans = "";
  int cnt = 0;
  int n = src.size();
  
  for(int i =0; i < n - 1; i++){
      if(src[i] == src[i+1]){
          cnt = cnt + 1;
      }else{
          ans += src[i];
          ans += to_string(cnt + 1);   
          cnt = 0;
    }
  }
  ans += src[n - 1];
  ans += to_string(cnt + 1);
  return ans;
}     
 