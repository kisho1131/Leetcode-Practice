class Solution {
public:
    bool isPossible(vector<int>&arr, int speed, int maxH){
            int currH= 0;
        for(int i =0;i<arr.size();i++){
            // (p + m - 1) / m equal to ceil(p / m) (just personal behavior)
            // currH += (arr[i] + speed - 1) / speed;
            currH += ceil(arr[i]*1.0 / speed);
        }
        return currH <= maxH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int ed = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        if(h == piles.size()) return ed;
        while(st <= ed){
            int speed = st + (ed-st)/2;
            if(isPossible(piles, speed, h ) == true){
                ed = speed - 1;
                ans = speed;
            }
            else
                st = speed  + 1;
        }
        return ans;
    }
};