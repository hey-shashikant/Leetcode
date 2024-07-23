from typing import List 

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        map = {}
        for num in nums:
            map[num] = map.get(num, 0) + 1
        for value in map.values():
            if value >= 2:
                return True
        return False
    
solution = Solution()
nums = list(map(int,input().split()))
if (solution.containsDuplicate(nums)):
    print("Contains duplicate")
else:
    print("Does not contain duplicates")
