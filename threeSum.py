class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            begin,end = i+1, len(nums)-1
            while begin < end:
                sum = nums[i] + nums[begin] + nums[end]
                if sum == 0:
                    temp = [nums[i],nums[begin],nums[end]]
                    res.append(temp)
                    while begin <= end and nums[begin] == temp[1]:
                        begin += 1
                    while end >= 0 and nums[end] == temp[2]:
                        end -= 1
                elif sum > 0:
                    end -= 1
                else:
                    begin += 1
            
        return res
