class Solution {
public:
    int romanToInt(string s) {
        map<char, int>mp; 
        // {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},{'D', 500}, {'M', 100}};
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});
        int n = s.length();
        int result = mp[s[n-1]];
        // cout<<result;
        for(int i = n-2;i>=0;i--){
            if(mp[s[i]] < mp[s[i+1]])
                result -=  mp[s[i]];
            else
                result += mp[s[i]];
        }
        return result;
    }
};