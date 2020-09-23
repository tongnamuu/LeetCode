class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        for start in range(0, n):
            v = start
            now = gas[v]
            for i in range(0, n):
                now -= cost[v]
                v += 1
                if v == n:
                    v = 0
                if now < 0:
                    break
                now += gas[v]

            if now >= 0:
                return start

        return -1
