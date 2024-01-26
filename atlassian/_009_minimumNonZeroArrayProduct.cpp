class Solution {
public:
    int minNonZeroProduct(int p) {
        long long mod = 1e9 + 7;
        long long q = (((long long)1 << p) - 2) % mod;
        long long r = (((long long)1 << p) - 1) % mod;
        long long ans = 1;
        while(--p){
            ans = ans * ans;
            ans = ans % mod;
            ans = ans * q;
            ans = ans % mod;
        }
        ans = ans * r;
        ans = ans % mod;
        return ans;
    }
};