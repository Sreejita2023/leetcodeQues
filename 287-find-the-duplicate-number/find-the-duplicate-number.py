class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow = nums[0]
        fast=nums[nums[0]]
        while slow!=fast:
            slow=nums[slow]
            fast=nums[nums[fast]]
        finder=0
        while slow!=finder:
            finder=nums[finder]
            slow=nums[slow]
        return slow

