from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits)-1
        carry = 1
        res = []
        while i >= 0 or carry:
            sum = carry
            if i >= 0:
                sum += digits[i]
            res.append(sum%10)
            carry = sum//10
            i -= 1
        return res[::-1]
        
            
solution = Solution()
digits = list(map(int,input().split()))
res = solution.plusOne(digits)
print(res)
