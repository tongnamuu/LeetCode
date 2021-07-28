class Solution:
    def beautifulArray(self, n: int) -> List[int]:
        d = {1:[1]}
        def dp(n):
            if n not in d:
                a = dp((n+1)//2)
                b = dp(n//2)
                d[n] = [x*2 - 1 for x in a] + [x*2 for x in b]
            return d[n]
        return dp(n)
