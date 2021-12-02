class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def solve(numbers, target, idx, val_list):
            if target < 0:
                return
            if target == 0:
                ans_list.append(val_list[:])
                return
            for i in range(idx, len(numbers)):
                num = numbers[i]
                val_list.append(num)
                solve(numbers, target - num, i, val_list)
                val_list.pop()
        ans_list = []
        solve(candidates, target, 0, [])
        return ans_list
