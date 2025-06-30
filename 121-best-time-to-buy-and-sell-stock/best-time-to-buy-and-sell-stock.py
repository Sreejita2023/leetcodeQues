class Solution:
    def maxProfit(self, prices: List[int]) -> int:
         max_cur = 0
         max_so_far = 0
         
         for i in range(1, len(prices)):
             max_cur = max(0, max_cur + prices[i] - prices[i - 1])
             max_so_far = max(max_so_far, max_cur)
         
         return max_so_far