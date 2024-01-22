class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int st=0,e=0,res=0,cnt=0,size=0;
        while(e<s.size()){
        cnt+=abs(s[e]-t[e]);
            if(cnt>maxCost) {
                cnt-=abs(s[st]-t[st]);
                st++; size--;
            }
            size++;
            res=max(res,size);
            e++;
        }
        return res;
    }
};