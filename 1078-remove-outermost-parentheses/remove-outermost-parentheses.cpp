class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int count = 0;
        for(char & c : s) {
            if(c == '(') {
                if(count > 0) res.push_back(c);
                count++;
            } else {
                count--;
                if(count > 0) res.push_back(c);
            }
        }
        return res;
    }
};