class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        temp = '123456789'
        l = str(low)
        h = str(high)
        ans = []
        for i in range(len(l), len(h)+1):
            for j in range(len(temp)):
                if j+i > len(temp):
                    break
                hubo = temp[j:j+i]
                val = int(hubo)
                if low <= val <= high:
                    ans.append(val)
        return ans

        