class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        int n = s.length();
        for(int i = 0; i<n; i++) {
            last[s[i]] = i;
        }
        vector<int> res;
        int start = 0 , end = 0;
        for(int i = 0; i<n; i++) {
            end = max(end,last[s[i]]);
            if(i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};