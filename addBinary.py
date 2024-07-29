class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        res = ""
        i,j = len(a)-1,len(b)-1
        while i >= 0 or j >= 0 or carry:
            sum = carry
            if i >= 0:
                sum += ord(a[i]) - ord('0')
                i -= 1
            if j >= 0:
                sum += ord(b[j]) - ord('0')
                j -= 1
            
            res += str(sum%2)
            carry = sum // 2
        
        return res[::-1]