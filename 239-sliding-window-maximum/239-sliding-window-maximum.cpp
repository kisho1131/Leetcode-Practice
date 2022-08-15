class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i =0;
        int j =0;
        list<int>l;
        vector<int>ans;
        while(j < nums.size()){
            if(l.size() != 0){
                while(l.size() > 0 and l.back() < nums[j])
                    l.pop_back();
            }
            l.push_back(nums[j]);
            
            if(j-i+1 < k) j++;
            else if(j - i + 1 == k){
                ans.push_back(l.front());
                
                if(nums[i] == l.front())
                    l.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};