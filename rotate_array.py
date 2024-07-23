from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n
        def reverse(start: int, end: int) -> int:
            while start < end:
                nums[start],nums[end] = nums[end],nums[start]
                start += 1
                end -= 1
        reverse(0,(n-k)-1)
        reverse((n-k),n-1)
        reverse(0,n-1)

solution = Solution()
k = int(input())
nums = list(map(int,input().split()))
solution.rotate(nums,k)
print(nums)
        