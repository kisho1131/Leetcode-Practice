class Solution {
public:
    int binaryMultiply(int a, int b, int mod){
        int ans = 0;
        a = a % mod;
        while(b > 0){
            if(b & 1)
                ans = (ans + a)%mod;
            a = (a + a)%mod;
            b >>=1;
        }
        return ans;
    }
    int binaryExp(int a, int b, int mod){
        int ans = 1;
        while(b > 0){
            if(b & 1)
                ans = binaryMultiply(ans, a, mod);
            a = binaryMultiply(a, a, mod);
            b >>=1;
        }
        return ans;
    }
    int solve(vector<int>b, int M){
        int ans = 0;
        int n = b.size();
        for(int i =0;i<n;++i){
            ans += (b[n-i-1] * binaryExp(10, i, M)) % M;
        }
        // cout<<"B="<<ans;
        return ans;
    }

    int superPow(int a, vector<int>& b) {
        int M = 1140;
        int mod = 1337;
        int num = solve(b, M);
        return binaryExp(a, num, mod);
    }
};