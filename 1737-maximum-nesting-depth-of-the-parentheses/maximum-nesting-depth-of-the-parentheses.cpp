class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxc = 0;
        for(char c : s) {
            if(c == '(') count++;
            else if(c == ')') count--;
            maxc = max(maxc,count);
        }
        return maxc;
    }
};