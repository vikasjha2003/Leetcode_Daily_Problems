class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].length();
        vector<string> res;
        for(string &str : queries) { 
            for(string &s : dictionary) {
                int cnt = 0;
                for(int idx = 0; idx < n; idx++) {
                    if(str[idx] != s[idx]) cnt++;
                    if (cnt > 2) break;
                }
                if(cnt <= 2) {
                    res.push_back(str);
                    break;
                }
            }
        }
        return res;
    }
};