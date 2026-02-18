class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> res;
        while(n>0) {
            res.push_back(n%2);
            n /= 2;
        }
        for(int i = 1; i < res.size(); i++) {
            if(res[i-1] == res[i]) return false;
        }
        return true;
    }
};