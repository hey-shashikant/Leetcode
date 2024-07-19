class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxReach = 0
        for i in range(len(nums)):
            if maxReach < i:
                return False
            maxReach = max(maxReach, i + nums[i])
        return True