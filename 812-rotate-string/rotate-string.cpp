class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.length();
        int m = s.length();
        if(n != m) return false;
        s += s;
        char c = goal[0];
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == c) {
                string str = s.substr(i,n);
                if(str == goal) return true;
            }
        }
        return false;
    }
};