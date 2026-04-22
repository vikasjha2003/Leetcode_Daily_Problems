class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();
        int o = queries[0].length();
        vector<string> res;
        for(int i = 0; i<n; i++) {
            string &str = queries[i]; 
            for(int j = 0; j<m; j++) {
                string &s = dictionary[j];
                int cnt = 0;
                for(int k = 0; k<o; k++) {
                    if(str[k] != s[k]) cnt++;
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