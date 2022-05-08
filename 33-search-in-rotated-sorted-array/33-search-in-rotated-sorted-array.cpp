class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size()-1;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(nums[mid] == target) return mid;
            
            // If the first half is sorted
            if(nums[st] <= nums[mid]){
                if(target >= nums[st] && target <= nums[mid])
                    ed = mid -1;
                else
                    st = mid +1;
            }
            
            // If the Second Half is Sorted
            if(nums[mid ]<= nums[ed]){
                if(target >= nums[mid] && target <= nums[ed])
                    st = mid +1;
                else
                    ed = mid -1;
            }
        }
        return -1;
    }
};