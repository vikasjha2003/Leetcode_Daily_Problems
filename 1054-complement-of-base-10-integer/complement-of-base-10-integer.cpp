class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        vector<int> num;
        while(n > 0) {
            num.push_back(!(n%2));
            n /= 2;
        }
        int cnt = 1;
        int res = 0;
        for(int i = 0; i < num.size(); i++) {
            res += num[i]*cnt;
            cnt *= 2;
        }
        return res;
    }
};