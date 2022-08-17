class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int prefixlen = INT_MAX;
        string ptr = "";
        int minlen = INT_MAX;
        int idx = -1;
        for(int i =0;i<strs.size();i++){
            int len = strs[i].length();
            if(len < minlen){
                minlen = len;
                idx = i;
            }
        }
        
        ptr = strs[idx];
        // cout<<ptr<<" ";
        for(int i =0;i<strs.size();i++){
            string temp = strs[i];
            //cout<<temp<<"->";
            int prefix= 0;
            for(int j=0;j<ptr.size();j++){
                if(ptr[j] != temp[j])
                    break;
                prefix++;
            }
            prefixlen = min(prefixlen, prefix);
            // cout<<endl;
            // cout<<prefixlen <<"->";
        }
        // cout<<prefixlen;
        if(prefixlen != INT_MAX)
            return ptr.substr(0, prefixlen);
        return ans;
    }
};