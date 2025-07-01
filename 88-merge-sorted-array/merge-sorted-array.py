class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if n==0:
            return
        if m==0:
            nums1[:]=nums2
            return 
        i=m-1
        k=len(nums1)-1
        j=n-1
        while j>=0 and i>=0:
          if nums2[j]>=nums1[i]:
            nums1[k]=nums2[j]
            j-=1
            k-=1
          else:
            nums1[k],nums1[i]=nums1[i],nums1[k]
            i-=1
            k-=1
        while j>=0:
            nums1[k]=nums2[j]
            j-=1
            k-=1
        