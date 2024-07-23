from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        map = {}
        for num in nums:
            map[num] = map.get(num, 0) + 1
        i = 0
        for key in map.keys():
            nums[i] = key 
            i += 1
        return i 

solution = Solution()
nums = list(map(int,input().split()))
res = solution.removeDuplicates(nums)
print(res)
print(nums)