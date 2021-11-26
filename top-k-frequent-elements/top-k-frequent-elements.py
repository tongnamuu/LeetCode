class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        x = collections.Counter(nums).most_common(k)
        ans = [arg[0] for arg in x]
        return ans