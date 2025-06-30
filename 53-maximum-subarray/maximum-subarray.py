class Solution:
    
    def maxSubArray(self, nums: List[int]) -> int:
        ans=-inf
        curr=0
        for i in range (len(nums)):
            curr=max(nums[i],curr+nums[i])
            ans=max(curr,ans)
        return ans