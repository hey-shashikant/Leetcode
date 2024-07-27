class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,j = 0,0
        maxLen = 0
        freq = [0]*128
        while j < len(s):
            if freq[ord(s[j])] == 0:
                freq[ord(s[j])] += 1
            else:
                while freq[ord(s[j])] != 0:
                    freq[ord(s[i])] -= 1
                    i += 1
                freq[ord(s[j])] += 1
            maxLen = max(maxLen, (j-i)+1)
            j += 1
        
        return maxLen