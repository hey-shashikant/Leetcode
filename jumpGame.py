class Solution:
    def canJump(self, nums: List[int]) -> bool:
        canReach = 0
        for i in range(len(nums)-1):
            canReach = max(canReach, i + nums[i])
            if i >= canReach:
                return False
        
        return True