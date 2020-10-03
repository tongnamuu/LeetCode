class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = set()
        if k == 0:
            for i in range(1, len(nums)):
                if nums[i] == nums[i - 1]:
                    ans.add((nums[i], nums[i]))
            return len(ans)
        for num in nums:
            idx = bisect.bisect_left(nums, num+k)
            if idx < len(nums) and num + k == nums[idx]:
                ans.add((num, num+k))
        return len(ans)
