class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        pos_val, abs_val = 1, 1
        ans = nums[0]
        for n in nums:
            temp = (n, n * pos_val, n * abs_val)
            pos_val = max(temp)
            abs_val = min(temp)
            ans = ans if ans > pos_val else pos_val
            
        return ans