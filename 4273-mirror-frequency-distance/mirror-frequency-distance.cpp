class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> ch (26,0);
        vector<int> di (10,0);
        for(char &c : s) {
            if(c >= '0' && c <= '9') {
                di[c-'0']++;
            } else {
                ch[c-'a']++;
            }
        }

        int res = 0;

        for(int i = 0; i<13; i++) {
            if(i < 5) {
                res += abs(di[i] - di[9-i]);
            }
            res += abs(ch[i] - ch[25 - i]);
        }

        return res;
    }
};