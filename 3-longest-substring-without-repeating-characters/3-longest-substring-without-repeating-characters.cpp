class Solution {
public:
    // without repeating character == all unique character
    int lengthOfLongestSubstring(string s) {
        int i =0;
        int j =0;
        map<char, int>mp;
        int maxLen = 0;
        while(j < s.length()){
            mp[s[j]]++;
            if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            else if(mp.size() == j-i+1)
                maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};