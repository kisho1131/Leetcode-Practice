class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size()-1;
        int st = 0;
        int ed = n;
        vector<int>res;
        while(st <= ed){
            if(arr[ed] + arr[st] == target){
                res.push_back(st+1);
                res.push_back(ed+1);
                return res;
            }
            if(arr[ed] + arr[st] < target)
                st++;
            else
                ed--;
        }
        return res;
    }
};