from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        summ,maxSum = 0,-2**31
        for num in nums:
            summ += num
            if summ < num:
                summ = num
            if maxSum < summ:
                maxSum = summ
                
        return maxSum