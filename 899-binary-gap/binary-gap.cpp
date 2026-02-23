class Solution {
public:
    int binaryGap(int n) {
        vector<int> pos;
        int cnt = 0;
        while(n>0) {
            if(n%2 == 1) {
                pos.push_back(cnt);
            }
            cnt++;
            n /= 2;
        }
        int res = 0;
        for(int i = 1; i<pos.size(); i++) {
            res = max(res,pos[i] - pos[i-1]);
        }
        return res;
    }
};