class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int st = 0;
        int ed = arr.size()-1;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(arr[mid] == target) return mid;
            else if(target < arr[mid])
                 ed = mid-1;
            else
                st = mid+1;
        }
        return st;
    }
};