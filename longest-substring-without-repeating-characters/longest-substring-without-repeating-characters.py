class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        positions = dict()
        i, j = 0, 0
        positions[s[0]] = 0
        ans = 1
        while j < len(s):
            temp = j - i + 1
            if temp > ans:
                ans = temp
            j += 1
            if j >= len(s):
                temp = j - i
                if temp > ans:
                    ans = temp
                break
            if s[j] in positions and positions[s[j]] >= i:
                i = positions[s[j]] + 1
            positions[s[j]] = j
        return ans