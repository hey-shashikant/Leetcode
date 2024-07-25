class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31
        if x > INT_MAX - 1 or x < INT_MIN:
            return 0
        negative = x < 0
        if negative:
            x = -x
        num = 0
        while x:
            num = num*10 + x%10
            x = x//10
        if negative:
            num = -num
        if num > INT_MAX or num < INT_MIN:
            return 0
        return num