class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        int prev = 0;
        int cur = 1;
        for(int i = 2; i <= n; i++) {
            int temp = prev;
            prev = cur;
            cur = cur + temp;
        }
        return cur;
    }
};