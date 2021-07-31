class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        d = [-1]*(amount + 1)
        d[0] = 0
        for i in range(1, amount + 1):
            for j in coins:
                if i >= j and d[i-j] != -1:
                    d[i] = min(d[i], d[i-j] + 1) if d[i] != -1 else d[i-j] + 1
        return d[amount]
    