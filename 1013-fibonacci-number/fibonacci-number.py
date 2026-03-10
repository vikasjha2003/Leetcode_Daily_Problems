class Solution:
    def fib(self, n: int) -> int:
        cur = 1
        prev = 0
        if n == cur or n == prev : return n
        for i in range(2,n+1) :
            temp = cur + prev
            prev = cur
            cur = temp
        return cur
