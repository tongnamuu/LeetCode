class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        def cal(w):
            ans = 0
            prev = 0
            for down, up in intervals:
                down = max(down, prev)
                
                if up > down:
                    ans += (up-down)*w
                    prev = up
            return ans
        
        MOD = 1000000007
        
        coords = []
        for x1, y1, x2, y2 in rectangles:
            coords.append((x1,0,y1,y2))
            coords.append((x2,1,y1,y2))
            
        coords.sort()
        intervals = []
        ans = 0
        prev = 0
        for x, e, y1, y2 in coords:
            ans += cal(x - prev)
            ans %= MOD
            if e == 1:
                intervals.remove((y1, y2))
            else:
                intervals.append((y1, y2))
                intervals.sort()
            prev = x
        return ans
    