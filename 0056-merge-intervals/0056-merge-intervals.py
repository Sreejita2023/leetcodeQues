class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: (x[0],x[1]))
        ans=[]
        for i in range(len(intervals)):
          if ans and ans[-1][0]<=intervals[i][0] and ans[-1][1]>=intervals[i][0] :
             ans[-1][1]=max(intervals[i][1],ans[-1][1])
          else:
            ans.append(intervals[i])
        return ans
        