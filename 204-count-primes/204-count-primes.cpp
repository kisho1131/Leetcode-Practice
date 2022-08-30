class Solution {
private:
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        int count = 0;
        // n = sqrt(n);
        vector<int>is_prime(n+1, 1);
        is_prime[0] = is_prime[1] = 0;
            for(int i = 2;i<n;++i){
                if(is_prime[i]){
                    count++;
                    for(int j = 2*i; j<n;j+=i)
                        is_prime[j] = 0;
                } 
            }
        return count++;
      }
};