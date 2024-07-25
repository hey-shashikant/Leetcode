class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(haystack) == 1:
            if haystack[0] == needle[0]:
                return 0
        for i in range(len(haystack) - len(needle)+1):
            j,k = 0,i
            while j < len(needle):
                if needle[j] == haystack[k]:
                    j += 1
                    k += 1
                else:
                    break
            if j == len(needle):
                return i
        return -1