class Solution:
    class ComplexA:
        def __init__(self, s):
            self.x, self.y = s.split("+")
            self.x = int(self.x)
            self.y = int(self.y[:-1])
        def __mul__(self, o):
            a = self.x*o.x - self.y*o.y
            b = self.x*o.y + self.y*o.x
            return f'{a}+{b}i'
        
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        z1 = Solution.ComplexA(num1)
        z2 = Solution.ComplexA(num2)
        return z1*z2
