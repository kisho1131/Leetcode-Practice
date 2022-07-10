class Solution {
public:
    vector<string>ans;
    void solution(string &str, int open, int close){
        
        if(open == 0 and close ==0){
            ans.push_back(str);
            return;
        }
        
        if(open > 0){
            str.push_back('(');
            solution(str, open-1,close);
            str.pop_back();
        }
        
        if(close > 0){
            if(open < close){
                str.push_back(')');
                solution(str, open, close-1);
                str.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        solution(str, n, n);
        return ans;
    }
};