class Solution {
public:
    bool isPerfectSquare(int num) {
        long long  st =1;
        long long  ed = num;
        while(st <= ed){
            long mid = st + (ed-st)/2;
            if(mid * mid == num)
                return true;
            else if(mid*mid > num)
                ed = mid -1;
            else
                st = mid +1;
        }
        return false;
    }
};