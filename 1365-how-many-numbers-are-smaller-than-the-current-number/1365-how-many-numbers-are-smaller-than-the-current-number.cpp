class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int>mp;
        vector<int>temp = nums;
        int n = nums.size();
        
        sort(temp.begin(), temp.end());
        for(int i = n-1;i>=0;i--)
            mp[temp[i]] = i;
        
        for(int i =0;i<n;i++)
            nums[i] = mp[nums[i]];
        
        return nums;
    }
};