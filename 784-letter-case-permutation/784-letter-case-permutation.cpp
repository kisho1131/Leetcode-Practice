class Solution {
public:
    void solution(string ip,string op, vector<string>&ans){
        if(ip.length() == 0){
            ans.push_back(op);
            return;
        }
        if(isalpha(ip[0])){
            string op1 = op;
            string op2 = op;
            op1.push_back(tolower(ip[0]));
            op2.push_back(toupper(ip[0]));
            ip.erase(ip.begin() + 0);
            solution(ip, op1, ans);
            solution(ip, op2, ans);
        }
        else{
            string op1 = op;
            op1.push_back(ip[0]);
            ip.erase(ip.begin()+0);
            solution(ip, op1,ans);
        }
        return;
    }
    vector<string> letterCasePermutation(string str) {
        vector<string>ans;
        if(str.length() == 0) return ans;
        string ip = str;
        string op = "";
        solution(ip, op, ans);
        return ans;
    }
};