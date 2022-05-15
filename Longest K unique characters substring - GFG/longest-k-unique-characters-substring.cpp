// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i =0;
        int j =0;
       // int n = s.length();
        map<char, int>mp;
        int maxWindow = -1;
        while(j < s.length()){
            mp[s[j]]++;
            if(mp.size()==k) 
                 maxWindow = max(maxWindow, (j-i+1));
            else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxWindow;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends