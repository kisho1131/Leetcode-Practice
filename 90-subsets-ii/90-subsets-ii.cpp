class Solution {
public:
    
    void helper(vector<int>&nums, int n, vector<int>&ds, vector<vector<int>>&ans){
        ans.push_back(ds);
        // helper(nums, n+1, ds);
        for(int i = n; i<nums.size();i++){
            if(i != n and nums[i] == nums[i-1]) continue; // avoid the duplicate
            // helper(nums, n+1, ds);
            
            ds.push_back(nums[i]);
            helper(nums, i+1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        // set<vector<int>>res;
        vector<int>ds;
        //int n = 0;
        helper(nums, 0, ds, ans);
        // for(auto itr = res.begin(); itr!=res.end(); itr++){
        //     vector<int>temp = *itr;
        //     ans.push_back(temp);
        // }
        return ans;
    }
};