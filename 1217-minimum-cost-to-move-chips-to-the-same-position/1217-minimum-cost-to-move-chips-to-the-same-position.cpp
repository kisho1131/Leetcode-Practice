class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int cost = 0;
        // map<string,int>mp;
        // string s1 = "even";
        // string s2 = "odd";
        int even = 0;
        int odd = 0;
        for(int i =0;i<pos.size();i++){
            if(pos[i]%2==0)
                even++;
            else
                odd++;
        }
        cost = min(even,odd);
        return cost;
    }
};