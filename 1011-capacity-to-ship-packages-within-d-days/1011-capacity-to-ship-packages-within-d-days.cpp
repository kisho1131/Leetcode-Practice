class Solution {
public:
    bool isPossible(vector<int>arr, int mid, int days){
        int currWt= 0;
        int daysCount= 1;
        for(int i =0;i<arr.size();i++){
            currWt += arr[i];
            if(currWt > mid){
                daysCount++;
                currWt = arr[i];
            }
            if(daysCount > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& wt, int days) {
        int st = *max_element(wt.begin(), wt.end());
        int ed = 0;
        for(int i =0;i<wt.size();i++)
            ed += wt[i];
        int res = -1;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(isPossible(wt, mid, days)){
                res = mid;
                ed = mid-1;
            }
            else
                st = mid+1;
        }
        return res;
    }
};