class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int cost = 0;
        map<string,int>mp;
        string s1 = "even";
        string s2 = "odd";
        for(int i =0;i<pos.size();i++){
            if(pos[i]%2==0)
                mp[s1]++;
            else
                mp[s2]++;
        }
        cost = min(mp[s1], mp[s2]);
        return cost;
    }
};