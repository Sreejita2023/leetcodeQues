class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            return self.myPow(1/x,abs(n))
        elif n==1:
            return x
        elif n==0:
            return 1
        elif n%2!=0:
           return x*self.myPow(x,n-1)
        else:
            return self.myPow(x*x,n/2)