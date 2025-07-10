class Solution:
        def minTime(self, n: int, edges: List[List[int]], k: int) -> int:
            def find(x):
                if x == f[x]:
                    return x
                f[x] = find(f[x])
                return f[x]
    
            def union(x, y):
                x = find(x)
                y = find(y)
                if x == y:
                    return False
                f[x] = y
                return True
    
            edges.sort(key = lambda e: -e[2])
            count = n
            f = list(range(n))
            for u, v, t in edges:
                if union(u, v):
                    count -= 1
                if count < k:
                    return t
            return 0
        