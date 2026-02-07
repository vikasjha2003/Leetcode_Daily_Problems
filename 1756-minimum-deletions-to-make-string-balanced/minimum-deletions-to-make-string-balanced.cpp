class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0;
        int res = INT_MAX;
        for(char i : s) if(i == 'a') a++;
        if(a ==  0 || a == s.length()) return 0;
        int b = 0;
        for(char &i : s) {
            if(i == 'a') {
                a--;
                res = min(res , a+b);
            } else {
                res = min(res , a+b);
                b++;
            }
        }
        return res;
    }
};