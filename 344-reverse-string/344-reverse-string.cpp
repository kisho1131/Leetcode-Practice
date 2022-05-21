class Solution {
public:
    void reverseString(vector<char>& str) {
        if(str.size() == 1 || str.size() == 0)
            return;
        char ch = str[0];
        str.erase(str.begin()+0);
        reverseString(str);
        str.push_back(ch);
    }
};