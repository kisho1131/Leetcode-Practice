class Solution {
public:
    string sortSentence(string s) {
        stringstream words(s);
        // map<string, int>mp;
        // vector<int>ans;
        vector<pair<int, string>>temp;
        
        string word;
        while(words >> word){
            int len = word.size();
            int i = int(word[len-1]) - 48;
            temp.push_back(make_pair(i, word.substr(0, len-1)));
        }
        
        sort(temp.begin(), temp.end());
        
        string ans = "";
        int n = temp.size();
        for(int i =0;i<n;i++){
            ans += temp[i].second;
            if(i!= n-1)
                ans+= " ";
        }
        return ans;
    }
};