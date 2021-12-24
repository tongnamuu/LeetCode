class Solution:
    class A(list):
        def __lt__(self, o):
            if self[0] == o[0]:
                return self[1] < o[1]
            return self[0] < o[0]
            
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def solve(x, y):
            if x[0] > y[0]:
                x, y = y, x
            if x[1] < y[0]:
                return x, y
            else: 
                return None, [x[0], max(x[1], y[1])]
        intervals.sort()
        idx = 1
        prev = intervals[0]
        ans = []
        while idx < len(intervals):
            a, b = solve(prev, intervals[idx])
            if a is not None:
                ans.append(a)
            prev = b
            idx += 1
        ans.append(prev)
        return ans