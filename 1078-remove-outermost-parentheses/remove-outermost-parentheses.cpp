class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        stack<char> st;
        for(char & c : s) {
            if(st.empty()) st.push(c);
            else {
                if(c == '(') st.push(c);
                else st.pop();
                if(!st.empty()) res.push_back(c);
            }
        }
        return res;
    }
};