class Solution:
    def isVowel(self,ch) -> bool:
        str = "aeiouAEIOU"
        return ch in str
        
    def halvesAreAlike(self, s: str) -> bool:
        i,j=0,len(s)-1
        cnt = 0
        while i < j:
            if self.isVowel(s[i]):
                cnt += 1
            if self.isVowel(s[j]):
                cnt -= 1
            i += 1
            j -= 1
        return (cnt == 0)