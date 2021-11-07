class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        ans, min_value = 0, prices[0]
        for p in prices:
            ans = p - min_value if p - min_value > ans else ans
            min_value = min_value if min_value < p else p
        return ans
    