class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        buy=prices[n-1]
        sell=prices[n-1]
        ans=0
        for i in range(n-2,-1,-1):
            curr=prices[i]
            if curr>sell:
               sell=curr
               buy=curr
            else:
              buy=min(curr,buy)
              ans=max(ans,sell-buy)
        return ans