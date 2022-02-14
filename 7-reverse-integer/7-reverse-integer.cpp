class Solution {
public:
    int reverse(int x) {
		int res=0;
		int max = INT_MAX/10;
		int min = INT_MIN/10;

		while(x)
		{
			int digit = x%10;

			if((res >=0 && res < max)||
			   (res == max && digit < 7) ||
			   (res < 0 && res > min) ||
			   (res == min && digit<8))

				res = res*10+digit;
			else
				return 0;
			x/=10;
		}
		return res;
	}
};