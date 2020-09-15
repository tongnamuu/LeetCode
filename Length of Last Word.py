class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        word_list = s.split(' ')
        for word in reversed(word_list):
            if len(word) > 0:
                return len(word)
        return 0
