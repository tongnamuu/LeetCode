class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        rest = [g - c for g, c in zip(gas, cost)]
        if sum(rest) < 0:
            return -1
        v = rest[0]
        ans = 0
        for i in range(1, n):
            rest[i] += rest[i - 1]
            if rest[i] < v:
                ans = i
                v = rest[i]

        if ans == n - 1:
            return 0
        return ans + 1
