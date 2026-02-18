class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> res;
        res.push_back(n%2);
        n /= 2;
        while(n>0) {
            int a = n%2;
            if(res.back() == a) return false;
            res.push_back(a);
            n /= 2;
        }
        return true;
    }
};