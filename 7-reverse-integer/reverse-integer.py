class Solution:
    def reverse(self, x: int) -> int:
        a = abs(x)
        rev = 0
        INT_MAX = 2**31 - 1
        while a > 0 :
            rev = rev*10 + a%10
            a //= 10
        if rev > INT_MAX : 
            return 0
        if x < 0 :
            return -1 * rev
        return rev