class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        if n == 1:
            return True
        x = 1
        temp = set()
        while x <= 1000000000:
            y = str(x)
            y = str(sorted(y))
            temp.add(y)
            x *= 2
        z = str(sorted(str(n)))
        return z in temp