class Solution {
public:
    vector<vector<int>>subset;
    void helper(vector<int>&arr, int n, vector<int>&nums){
        if(n == nums.size()){
            subset.push_back(arr);
            return;
        }
        
        helper(arr, n+1, nums);
        
        arr.push_back(nums[n]);
        helper(arr, n+1, nums);
        arr.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        int n = 0;
        helper(arr,n,nums);
        return subset;
    }
};