class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter = collections.Counter(s)
        stack = []
        visit = set()
        for ch in s:
            counter[ch] -= 1
            if ch not in visit:
                while stack and stack[-1] > ch and counter[stack[-1]]:
                    visit.remove(stack[-1])
                    stack.pop()
                visit.add(ch)
                stack.append(ch)
        return ''.join(stack)
