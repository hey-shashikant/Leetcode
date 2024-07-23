from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single = 0
        for num in nums:
            single = num ^ single
        return single
    
solution = Solution()
nums = list(map(int,input().split()))
single_number = solution.singleNumber(nums)
print(single_number)