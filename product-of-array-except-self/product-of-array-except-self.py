class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        num = 1
        ans = [0] * len(nums)
        for idx, i in enumerate(nums):
            ans[idx] = num
            num *= i
        
        num = 1
        for i in range(len(nums) - 1, -1, -1):
            ans[i] *= num
            num *= nums[i]
        return ans