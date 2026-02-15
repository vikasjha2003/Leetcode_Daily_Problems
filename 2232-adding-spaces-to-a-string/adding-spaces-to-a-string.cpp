class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int j = 0;
        string res = "";
        while(i < s.length()) {
            if(j<spaces.size() && i == spaces[j]) {
                res.push_back(' ');
                j++;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};