class Solution {
public:
    bool isPosssible(vector<int>&nums, int div, int th){
        int res = 0;
        for(int i =0;i<nums.size(); i++){
            res += ceil(nums[i]*1.0/div);
        }
        return res <= th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1;
        int ed = *max_element(nums.begin(), nums.end());
        cout<<ed;
        int res = INT_MAX;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(isPosssible(nums, mid, threshold)){
                res = mid;
                ed = mid -1;
            }
            else
                st = mid + 1;
        }
        return res;
    }
};