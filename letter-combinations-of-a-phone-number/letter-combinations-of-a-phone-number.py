class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        strs = [0, 0, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        if len(digits) == 0:
            return []
        elif len(digits) == 1:
            return list(strs[int(digits)])
        elif len(digits) == 2:
            ans = []
            for c1 in strs[int(digits[0])]:
                for c2 in strs[int(digits[1])]:
                    ans.append(c1+c2)
            return ans
        elif len(digits) == 3:
            ans = []
            for c1 in strs[int(digits[0])]:
                for c2 in strs[int(digits[1])]:
                    for c3 in strs[int(digits[2])]:
                        ans.append(c1+c2+c3)
            return ans
        elif len(digits) == 4:
            ans = []
            for c1 in strs[int(digits[0])]:
                for c2 in strs[int(digits[1])]:
                    for c3 in strs[int(digits[2])]:
                        for c4 in strs[int(digits[3])]:
                            ans.append(c1+c2+c3+c4)
            return ans