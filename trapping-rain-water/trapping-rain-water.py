class Solution:
    def trap(self, height: List[int]) -> int:
        s = []
        ans = 0
        for i, h in enumerate(height):
            while len(s) > 0 and height[i] > height[s[-1]]:
                top = s.pop()
                if not s:
                    break
                w = i - s[-1] -1
                h = min(height[i], height[s[-1]]) - height[top]
                ans += w*h
                
            s.append(i)
        return ans
    