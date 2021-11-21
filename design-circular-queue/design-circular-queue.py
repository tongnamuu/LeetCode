class MyCircularQueue:

    def __init__(self, k: int):
        self.k = k
        self.a = [0]*k
        self.sz = 0
        self.f = 0
        self.b = 0
    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False 
        self.sz += 1
        self.a[self.b] = value
        self.b += 1
        if self.b == self.k:
            self.b = 0
        return True
    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        res = self.a[self.f]
        self.f += 1
        if self.f == self.k:
            self.f = 0
        self.sz -= 1
        return True

    def Front(self) -> int:
        if self.isEmpty():
            return -1
        return self.a[self.f]

    def Rear(self) -> int:
        if self.isEmpty():
            return -1
        return self.a[self.b - 1]

    def isEmpty(self) -> bool:
        return self.sz == 0

    def isFull(self) -> bool:
        return self.sz == self.k


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()