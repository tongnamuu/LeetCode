class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            print(c, ord(c))
            if c in ('(', '{', '['):
                stack.append(c)
            else:
                if not stack:
                    return False
                if c ==')':
                    if ord(c) - ord(stack[-1]) != 1:
                        return False
                else:
                    if ord(c) - ord(stack[-1]) != 2:
                        return False
                stack.pop()
        return len(stack) == 0