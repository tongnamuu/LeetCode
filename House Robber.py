class Solution:
    def rob(self, nums: List[int]) -> int:
        d = [0]*(len(nums)+3)
        for i in range(3, len(nums)+3):
            d[i] = max(d[i - 2], d[i - 3]) + nums[i - 3]
        return max(d)
