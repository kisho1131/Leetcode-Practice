class Solution {
public:
    int First(vector<int>arr, int x){
        int start = 0;
        int n = arr.size();
          int end = n - 1;
          int res = -1;
          while (start <= end) {
            int mid = start + (end - start) / 2;
            if (x == arr[mid]) {
              res = mid;
              end = mid - 1;
            } else if (x < arr[mid])
              end = mid - 1;
            else
              start = mid + 1;
          }
          return res;
    }
    
    int Last(vector<int>arr, int x){
      int start = 0;
        int n = arr.size();
      int end = n - 1;
      int res = -1;
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (x == arr[mid]) {
          res = mid;
          start = mid + 1;
        } else if (x < arr[mid])
          end = mid - 1;
        else
          start = mid + 1;
      }
      return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        int firstOccur = First(nums, target);
        int lastOccur = Last(nums, target);
        if(firstOccur == -1){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        cout<<firstOccur;
        res.push_back(firstOccur);
        res.push_back(lastOccur);
        return res;
    }
};