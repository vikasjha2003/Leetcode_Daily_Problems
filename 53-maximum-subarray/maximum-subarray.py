class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum = -2**31
        sum = 0
        for num in nums :
            sum += num
            if maxsum < sum :
                maxsum = sum
            if sum < 0 :
                sum = 0
            
        return maxsum