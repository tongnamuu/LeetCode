class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        counter = collections.Counter(nums)
        return [k for k, v in counter.items() if v > len(nums)//3]
