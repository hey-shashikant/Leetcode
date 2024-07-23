class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        i = 0
        while i < len(haystack):
            j = 0
            if haystack[i] == needle[j]:
                k = i
                while k < len(haystack) and j < len(needle) and haystack[k] == needle[j]:
                    j += 1
                    k += 1
                if j == len(needle):
                    return i 
            i += 1
        return -1

solution = Solution()
haystack = input()
needle = input()
index = solution.strStr(haystack, needle)
print(index)
