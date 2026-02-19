class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int pre = 0;
        int cur = 1;
        int res = 0;
        for(int i = 1; i<n; i++) {
            if(s[i-1] == s[i]) cur++;
            else {
                res += min(pre,cur);
                pre = cur;
                cur = 1;
            }
        }
        res += min(cur,pre);
        return res;
    }
};