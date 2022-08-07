class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>&nums, vector<int>&ds, int freq[]){
        if(ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }
        
        for(int i =0;i<nums.size();i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                helper(nums, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        int freq[nums.size()];
        memset(freq, 0, sizeof(freq));
        helper(nums, ds, freq);
        return res;
    }
};
/*
    vector<vector<int>>res;
    void permute_rec(int st,int ed, vector<int>&nums){
        if(st >= ed){
            res.push_back(nums);
            return;
        }
        for(int i =st; i<=ed;i++){
            swap(nums[st], nums[i]);
            permute_rec(st+1, ed, nums);
            swap(nums[st], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       // int itr = 0;
        vector<int>arr;
        permute_rec(0,nums.size()-1,nums);
        return res;
    }
*/