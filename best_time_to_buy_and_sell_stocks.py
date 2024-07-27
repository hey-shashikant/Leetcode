class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum = 2**31
        profit = 0
        for price in prices:
            minimum = min(minimum,price)
            profit = max(profit, price-minimum)
        return profit
    
    