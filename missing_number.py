class Solution:
    def missingNumber(self, n, arr):
        actual_sum = (n*(n+1))//2
        array_sum = sum(arr)
        return actual_sum - array_sum

t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    solution = Solution()
    res = solution.missingNumber(n,arr)
    print(res)