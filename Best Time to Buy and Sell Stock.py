class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        ans, min_value = 0, prices[0]
        for p in prices:
            ans = max(p - min_value, ans)
            min_value = min(min_value, p)
        return ans
