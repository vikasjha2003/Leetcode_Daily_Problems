class Solution {
public:
    int binaryGap(int n) {
        vector<int> pos;
        int cnt = 0;
        int prev_cnt = -1;
        int res = 0;
        while(n>0) {
            if(n%2 == 1 && prev_cnt == -1) {
                prev_cnt = cnt;
            } else if (n%2 == 1) {
                res = max(res,cnt - prev_cnt);
                prev_cnt = cnt;
            }
            cnt++;
            n /= 2;
        }
        return res;
    }
};