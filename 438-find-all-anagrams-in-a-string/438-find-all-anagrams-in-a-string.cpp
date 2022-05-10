class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i =0, j =0;
        vector<int>res;
        int k = p.length();
        unordered_map<int, int>mp;
        for(auto ele : p)
            mp[ele]++;
        int count = mp.size();
        while(j < s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            if((j - i + 1) < k)
                j++;
            else if ( (j-i+1) == k){
                if(count == 0) res.push_back(i);
                
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1) count++;
                }
                i++;
                j++;
            }
        }
        
        return res;
    }
};