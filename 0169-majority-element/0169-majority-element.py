class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count=1
        ans=nums[0]
        for i in range(1,len(nums)):
            if nums[i]==ans:
                count+=1
                # print(nums[i] , count,"hello")
            else:
                count-=1
                # print(nums[i] , count)
                if count==0:
                    ans=nums[i]
                    count=1
        return ans