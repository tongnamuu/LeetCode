class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split(".")
        v2 = version2.split(".")
        for a, b in itertools.zip_longest(v1, v2, fillvalue=0):
            a = int(a)
            b = int(b)
            if a > b:
                return 1
            elif a < b:
                return -1
        return 0
