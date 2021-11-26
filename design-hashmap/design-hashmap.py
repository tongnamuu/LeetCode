class MyHashMap:

    def __init__(self):
        self.d = collections.defaultdict(int)

    def put(self, key: int, value: int) -> None:
        self.d[key] = value

    def get(self, key: int) -> int:
        return self.d.get(key) if self.d.get(key) is not None else -1

    def remove(self, key: int) -> None:
        if key in self.d:
            del self.d[key]


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)