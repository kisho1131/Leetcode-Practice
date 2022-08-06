class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>nums, int n, set<vector<int>>&res, vector<int>&ds){
        if(n == nums.size()){
            res.insert(ds);
            return;
        }
        
        helper(nums, n+1, res, ds);
        
        ds.push_back(nums[n]);
        helper(nums, n+1, res, ds);
        ds.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>res;
        vector<int>ds;
        int n = 0;
        helper(nums, n, res, ds);
        for(auto itr = res.begin(); itr!=res.end(); itr++){
            vector<int>temp = *itr;
            ans.push_back(temp);
        }
        return ans;
    }
};