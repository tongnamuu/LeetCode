class Solution:
    def isPalindrome(self, s: str) -> bool:
        cl = [ c.lower() for c in s if c.isalnum()]
        return cl == cl[::-1]