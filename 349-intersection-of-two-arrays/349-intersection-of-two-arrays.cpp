class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        vector<int>ans;
        for(auto ele : nums1)
            s1.insert(ele);
        set<int>s2;
        for(auto ele : nums2)
            s2.insert(ele);
        // int i = s2.size();
        for(auto ele : s2){
            if(s1.find(ele)!=s1.end())
                ans.push_back(ele);
        }
        return ans;
    }
};