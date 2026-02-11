class Solution {
public:
    int n ;
    void generate(string &s, vector<string> &res, int idx) {
        if(idx == n) {
            res.push_back(s);
            return;
        }
        generate(s,res,idx+1);
        if(s[idx] >= 'A' && s[idx] <= 'Z') {
            s[idx] = s[idx] + 32;
            generate(s,res,idx+1);
            s[idx] = s[idx] - 32;
        } 
        else if (s[idx] >= 'a' && s[idx] <= 'z') {
            s[idx] = s[idx] - 32;
            generate(s,res,idx+1);
            s[idx] = s[idx] + 32;
        }
    }

    vector<string> letterCasePermutation(string s) {
        n = s.length();
        vector<string> res;
        generate(s,res,0);
        return res;
    }
};