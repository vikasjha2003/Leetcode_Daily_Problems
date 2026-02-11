class Solution {
public:

    void generate(string &s, string ans , vector<string> &res, int idx) {
        if(idx == s.length()) {
            res.push_back(ans);
            return;
        }
        generate(s,ans + s[idx],res,idx+1);
        if(s[idx] >= 'A' && s[idx] <= 'Z') {
            char c = s[idx] + 32;
            generate(s,ans + c,res,idx+1);
        }
        else if (s[idx] >= 'a' && s[idx] <= 'z') {
            char c = s[idx] - 32;
            generate(s,ans + c,res,idx+1);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        generate(s,"",res,0);
        return res;
    }
};