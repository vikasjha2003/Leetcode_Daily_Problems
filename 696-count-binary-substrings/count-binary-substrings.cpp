class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> solve;
        int count = 1;
        for(int i = 1; i<n; i++) {
            if(s[i] == s[i-1]) count++;
            else {
                solve.push_back(count);
                count = 1;
            }
        }
        solve.push_back(count);
        int res = 0;
        for(int i = 1; i < solve.size(); i++) {
            res += min(solve[i],solve[i-1]);
        }
        return res;
    }
};