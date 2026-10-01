import sys

class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minPrice = sys.maxsize
        maxProfit = 0

        for price in prices:
            if price < minPrice:
                minPrice = price

            profit = price - minPrice
            maxProfit = max(maxProfit, profit)

        return maxProfit

if __name__ == '__main__':
    prices = list(map(int, input().split()))
    print(Solution().maxProfit(prices))
