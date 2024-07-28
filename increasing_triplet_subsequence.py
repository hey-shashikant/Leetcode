from typing import List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        c1,c2= 2**31,2**31
        for num in nums:
            if num <= c1:
                c1 = num  # this is the minimum element so far can be our c1
            elif num <= c2:
                c2 = num  # this can be c2 or c3
            else:
                return True
        return False