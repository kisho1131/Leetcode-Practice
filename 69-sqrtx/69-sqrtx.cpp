class Solution {
public:
    int mySqrt(int x) {
        int st = 1;
        int ed = x;
        int ans = 0;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(mid  <= x/mid){
                ans = mid;
                st = mid +1;
            }
            else
                ed = mid -1;
        }
        return ans;
    }
};