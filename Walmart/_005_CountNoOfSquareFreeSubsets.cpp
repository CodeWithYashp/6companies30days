class Solution {
private:
    int mod = 1000000007;
public:
    int add(int a, int b){
        a += b;
        if(a >= mod){
            a -= mod;
        }
        return a;
    }

    bool check(vector<int> v){
        for(int i : v){
            if( i > 1){
                return false;
            }
        }
        return true;
    }

    int squareFreeSubsets(vector<int>& nums) {
        vector<int> p, v(31,1);
        v[0] = v[1] = 0;

        for(int i = 2; i < 31; i++)
        {
            if(v[i])
            {
                p.push_back(i);
                for (int j = i + i; j < 31; j += i)
                    v[j] = 0;
            }
        }

        int n = nums.size();
        vector<int> prev(1 << 10);
        vector< vector<int>> f(n, vector<int>(10));
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            for(int j = 0; j < 10; j++)
            {
                while( x % p[j] == 0)
                {
                    x /= p[j];
                    f[i][j]++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            vector<int> nxt(prev.begin(), prev.end());

            if (check(f[i]))
            {
                int mask = 0;
                for (int j = 0; j < 10; j++)

                    if (f[i][j] == 1)
                    {
                        mask |= (1 << j);
                    }

                for (int j = 0; j < (1 << 10); j++)
                    if ((j & mask) == 0)
                        nxt[j | mask] = add(nxt[j | mask], prev[j]);

                nxt[mask] = add(nxt[mask], 1);
            }
            swap(prev, nxt);
        }

        int ans = 0;
        for (int i = 0; i < (1 << 10); i++)
            ans = add(ans, prev[i]);
        return ans;
    }
};