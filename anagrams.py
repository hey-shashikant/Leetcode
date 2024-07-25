class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = {}
        for char in t:
            freq[char] = freq.get(char,0) + 1
        for char in s:
            if char in freq:
                freq[char] -= 1
                if freq[char] == 0:
                    del freq[char]
            else:
                return False
        if len(freq) != 0:
            return False
        return True