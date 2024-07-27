# class Solution:
#     def isPalindrome(self, s: str) -> bool:
#         i, j = 0, len(s) - 1
#         while i < j:
#             if s[i] != s[j]:
#                 return False
#             i += 1
#             j -= 1
#         return True
    
#     def longestPalindrome(self, s: str) -> str:
#         maxLen = 0
#         res = ""
#         for i in range(len(s)):
#             strr = ""
#             for j in range(i,len(s)):
#                 strr += s[j]
#                 if self.isPalindrome(strr):
#                     if maxLen < len(strr):
#                         maxLen = len(strr)
#                         res = strr
        
#         return res
                    