class Solution {
public:
    // return min element or no of times the array is rotated is same
    int findMin(vector<int>& nums) {
        int st = 0;
        int n = nums.size();
        int ed = nums.size()-1;
        while(st <= ed){
            if(nums[st] <= nums[ed]) return nums[st];
            int mid = st + (ed-st)/2; // to avoid overflow
            int nextIdx = (mid + 1)%n;
            int prevIdx = (mid + n-1)%n;
            if(nums[mid] <= nums[nextIdx] && nums[mid] <= nums[prevIdx])
                return nums[mid];
            //  now we need to discard the sorted part of the array as the min element always prsent in the unsorted part of the array
            if(nums[st] <= nums[mid])
                st = mid +1;
            else if(nums[mid] <= nums[ed])
                ed = mid -1;
        }
        return -1;
    }
};