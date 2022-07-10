class Solution {
public:
    vector<vector<int>>subset;
    void generateSubset(vector<int>&arr, int n, vector<int>&nums){
        if(n == nums.size()){
            subset.push_back(arr);
            return;
        }
        // Do not Include
        generateSubset(arr, n+1,nums);
        
        // Include the Current Element
        arr.push_back(nums[n]);
        generateSubset(arr, n+1, nums);
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        generateSubset(arr, 0, nums);
        return subset;
        
    }
};