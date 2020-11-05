class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        x = collections.Counter(position)
        even, odd = 0, 0
        for pos, cnt in x.items():
            if pos % 2 == 0:
                odd += cnt
            else:
                even += cnt
        return min(even, odd)
