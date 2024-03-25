class Solution:
  def findDuplicates(self, nums: List[int]) -> List[int]:
      duplicates = []
      for i in range(len(nums)):
          if nums[abs(nums[i])-1] < 0:
              duplicates.append(abs(nums[i]))
          nums[abs(nums[i])-1] = -1 * nums[abs(nums[i])-1]
      return duplicates