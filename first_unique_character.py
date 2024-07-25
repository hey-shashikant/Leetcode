class Solution:
    def firstUniqChar(self, s: str) -> int:
        uMap = {}
        for char in s:
            uMap[char] = uMap.get(char,0) + 1
        for i in range(len(s)):
            if uMap[s[i]] == 1:
                return i;
        return -1