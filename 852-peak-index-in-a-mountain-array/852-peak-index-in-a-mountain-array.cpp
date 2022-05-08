class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int st = 1;
        int ed = nums.size()-2;
        int n =nums.size();
        if(n == 1) return 0;
        // check if 0th/n-1th index is the peak element
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        while(st <= ed){
            int mid = st + (ed-st)/2;
                if(nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1])
                    return mid;
                else if (nums[mid+1] > nums[mid])
                    st = mid+1;
                else if (nums[mid-1] > nums[mid])
                    ed = mid -1;
        }
        return -1;
    }
};