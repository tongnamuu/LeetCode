class Solution:
    def minDeletions(self, s: str) -> int:
        x = sorted(list(Counter(s).values()))
        cnt = 0
        for i in range(len(x)-1, 0, -1):
            if x[i] <= x[i-1]:
                if x[i]==0:
                    cnt += x[i-1]
                    x[i-1] = 0
                else:
                    cnt += 1 +  x[i-1] - x[i]
                    x[i-1] = x[i] - 1
        return cnt
                
                
            
        