from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for i in range(len(prices)-1):
            if prices[i] < prices[i+1]:
                profit += prices[i+1] - prices[i]
        return profit
    
solution = Solution()
prices = list(map(int,input().split()))
profit = solution.maxProfit(prices)
print(profit)