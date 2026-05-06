class Solution {
    public int reverse(int x) {
        int a = Math.abs(x);

        int rev = 0;

        while(a > 0) {
            int digit =  a%10;
            a /= 10;
            if(rev  > (Integer.MAX_VALUE - digit) / 10) {
                return 0;
            }
            rev = rev*10 + digit;
        }

        return x < 0 ? -rev : rev;
    }
}