class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        def dfs(n, k, prev, cnt, temp, ans):
            if cnt == k:
                ans.append(temp[:])
                return
            for i in range(prev+1, n+1):
                temp.append(i)
                dfs(n, k, i, cnt + 1, temp, ans)
                temp.pop()
        ans = []
        temp = []
        dfs(n, k, 0, 0, temp, ans)
        return ans