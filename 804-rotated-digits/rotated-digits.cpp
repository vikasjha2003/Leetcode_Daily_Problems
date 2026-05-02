class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> rot = {0,1,5,-1,-1,2,9,-1,8,6};
        int count = 0;

        for(int i = 1; i<=n; i++) {
            int a = i;
            int res = 0;
            int cnt = 1;
            while(a > 0) {
                if(rot[a%10] == -1) {
                    res = -1;
                    break;
                }
                res = res + rot[a%10] * cnt;
                cnt *= 10;
                a /= 10;
            }

            if(res != -1 && res != i) count++;
        }

        return count;
    }
};