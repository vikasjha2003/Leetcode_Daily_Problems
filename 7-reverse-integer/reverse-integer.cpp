class Solution {
public:
    int reverse(int x) {
        long x2 = x;
        int x1 = abs(x2);
        long rev = 0;
        while (x1>0) {
            rev = rev*10 + x1%10;
            x1/=10; 
        }
        if (rev>(pow(2,31)-1)) return 0;
        if (x<0) x = (-1*rev);
        else return rev;
        return x;
    }
};