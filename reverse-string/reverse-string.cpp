class Solution {
public:
    void rec(vector<char>&s, int left, int right){
        if(left >= right)
            return;
        swap(s[left++], s[right--]);
        rec(s, left, right);
        
    }
    void reverseString(vector<char>& s) {
        rec(s,0,s.size()-1);
    }
};