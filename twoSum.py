from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        uMap = {}
        for i in range(len(nums)):
            value = target - nums[i]
            if value in uMap:
                return [i, uMap[value]]
            uMap[nums[i]] = i
        
        return [-1,-1]
    
solution = Solution()
target = int(input())
nums = list(map(int,input().split()))
res = solution.twoSum(nums, target)
print(res)
