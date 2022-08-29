class Solution {
public:
    string convertToTitle(int num) {
        string ans = "";
        char temp;
        while(num > 0){
            num -= 1;
            temp = 'A' + num%26;
            ans  = temp+ans;
            num /= 26;
        }
        return ans;
    }
};