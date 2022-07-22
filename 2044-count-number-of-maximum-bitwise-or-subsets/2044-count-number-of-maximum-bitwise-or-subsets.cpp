class Solution {
public:
    void helper(vector<int>&arr, int n, vector<int>&nums, int &max, int &count){
        if(n == nums.size()){
            int currOr = 0;
            for(auto ele : arr){
                currOr |= ele;
            }
            if(currOr == max){
                ++count;
            }
            return;
        }
        
        helper(arr, n+1, nums, max, count);
        
        arr.push_back(nums[n]);
        helper(arr, n+1,nums, max, count);
        arr.pop_back();
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>arr;
        int n =0;
        int max = 0;
        int count = 0;
        for(auto ele : nums)
            max |= ele;
        helper(arr, n, nums, max, count);
        return count;
    }
};