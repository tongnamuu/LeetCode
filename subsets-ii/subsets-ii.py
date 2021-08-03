class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        c = set();
        ans = []
        for i in range(1<<n):
            temp = []
            for j in range(n):
                if i & (1<<j):
                    temp.append(nums[j])
            temp.sort()
            if tuple(temp) not in c:
                ans.append(temp)
                c.add(tuple(temp))
        return ans
