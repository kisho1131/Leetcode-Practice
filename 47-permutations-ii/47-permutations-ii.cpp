class Solution {
public:
    set<vector<int>>res;
    void helper_(vector<int>&arr, int st, int ed){
        if( st >= ed){
            res.insert(arr);
            return;
        }
        for(int i = st; i<=ed;i++){
            swap(arr[st], arr[i]);
            helper_(arr, st+1, ed);
            swap(arr[st], arr[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper_(nums, 0, nums.size()-1);
        vector<vector<int>>ans;
        for(auto itr = res.begin(); itr!=res.end();itr++){
            vector<int> temp = *itr;
            ans.push_back(temp);
        }
        return ans;
    }
};