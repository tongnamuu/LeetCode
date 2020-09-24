class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        for a, b in itertools.zip_longest(sorted(s), sorted(t), fillvalue='!'):
            if a != b:
                return b
        return 'a'
