class Solution {
public:
    int reverseBits(int n) {
        vector<int> res (32,0);
        int cnt = 1;
        while (n>0) {
            if(n%2 == 1) {
                res[32 - cnt] = 1;
            }
            cnt++;
            n/=2;
        }
        long long it = 1;
        long long rev = 0;
        for (int i = 0; i<32; i++) {
            rev += res[i] * it;
            it *= 2;
        }
        return rev;
    }
};