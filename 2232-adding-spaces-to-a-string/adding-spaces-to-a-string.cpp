class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        string res = "";
        for(int i = 0; i<spaces.size(); i++) {
            while(j<spaces[i]) {
                res += s[j];
                j++;
            }
            res.push_back(' ');
        }
        while(j<s.length()) {
            res += s[j];
            j++;
        }
        return res;
    }
};