class Solution(object):
    def lexicalOrder(self, n):
        ans = [i for i in range(1, n+1)]
        return sorted(ans, key=lambda x: str(x))
    
        