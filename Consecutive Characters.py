class Solution:
    def maxPower(self, s: str) -> int:
        if len(s)==0:
            return 0
        prev = s[0]
        ans, cnt = 0, 1
        for i in range(1, len(s)):
            if s[i] == prev:
                cnt += 1
            else:
                ans = max(ans, cnt)
                cnt = 1
                prev = s[i]
        ans = max(ans, cnt)
        return ans
