class Solution {
public:
    bool isPossible(vector<int>arr, int m, int k, int days){
        int reqFlow = 0;
        int reqBou = 0;
        for(int i =0;i<arr.size();i++){
            if(arr[i] <= days){ 
                reqFlow++;
                if(reqFlow == k){
                    reqBou++;
                    reqFlow = 0;
                }
            }
            else reqFlow = 0;
        }
        if(reqBou >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int st = 1;
        cout<<st;
        int ed = INT_MAX-1;
        // for(int i =0;i<bloomDay.size();i++)
        //     ed += bloomDay[i];
        // cout<<ed;
        int res = -1;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(isPossible(bloomDay, m, k, mid)){
                res = mid;
                ed = mid-1;
            }
            else 
                st = mid+1;
        }
        return res;
    }
};