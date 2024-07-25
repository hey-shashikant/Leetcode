class Solution:
    def myAtoi(self, s: str) -> int:
        i,n = 0, len(s)
        while i < len(s) and s[i] == ' ':
            i += 1
        negative = False
        if i < n and (s[i] == '-' or s[i] == '+'):
            negative = s[i] == '-'
            i += 1
        
        res = 0
        while i < n and s[i].isdigit():
            res = res *10 + int(s[i])
            i += 1
 
        if negative:
            res = -res
            
        res = max(-2**31, min(res,2**31-1))
            
        return res
                