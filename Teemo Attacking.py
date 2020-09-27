class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries or not duration:
            return 0
        ans = duration
        for i in range(1, len(timeSeries)):
            ans += min(timeSeries[i] - timeSeries[i - 1], duration)
        return ans
