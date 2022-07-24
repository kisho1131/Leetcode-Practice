class Solution {
public:
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
};