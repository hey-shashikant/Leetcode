class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxLength = 1
        res = ""
        if len(s) < 2:
            return s
        for i in range(1, len(s)):
            left,right = i,i
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            left += 1
            if (right-left) >= maxLength:
                res = s[left:right]
                maxLength = (right-left)

            left,right = i-1,i
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            left += 1
            if (right-left) >= maxLength:
                res = s[left:right]
                maxLength = (right-left)

        return res

