class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        res = 0
        
        for people in range(1, n+1):
            res = (res + k) % people
        return res + 1
    
        def helper(n, k):
            if n==1:
                return 0
            return (helper(n-1, k) + k) % n
        
        return helper(n, k) + 1
