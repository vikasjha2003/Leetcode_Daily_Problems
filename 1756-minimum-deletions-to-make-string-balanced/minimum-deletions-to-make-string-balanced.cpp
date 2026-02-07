class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0;
        int res = s.length();
        for(char i : s) if(i == 'a') a++;
        int b = 0;
        for(char &i : s) {
            if(i == 'a')  a--;
            res = min(res , a+b);
            if(i == 'b') b++;            
        }
        return res;
    }
};