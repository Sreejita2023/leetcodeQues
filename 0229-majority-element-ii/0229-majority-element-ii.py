class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count1=0
        count2=0
        candidate1=0
        candidate2=0
        for num in nums:
          if count1==0 and candidate1!=num:
             count1+=1
             candidate1=num
          elif count2==0 and candidate2!=num:
             count2+=1
             candidate2=num
          elif candidate1!=num:
              count1+=1
          elif candidate2!=num:
              count2+=1
          else:
            count2-=1
            count1-=1
        threshold=len(nums)//3
        count1=0
        count2=0
        for num in nums:
            if candidate1 == num:
                count1+=1
            if candidate2 == num:
                count2+=1
        result=[]
        if(count1>threshold):
            result.append(candidate1)
        if(count2>threshold):
            result.append(candidate2)
        return result