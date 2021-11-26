class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        cnt = collections.Counter(stones)
        ans = sum(cnt[i] for i in jewels)
        return ans