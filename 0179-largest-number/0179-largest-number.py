from functools import cmp_to_key

class Solution(object):


    def largestNumber(self, nums):
        # Convert to string once
        nums = [str(num) for num in nums]
        # Compare function
        # Sort the numbers
        def compare(x, y):
            return int(y + x) - int(x + y)
        nums.sort(key=cmp_to_key(compare))
        # Join the numbers
        largest_num = ''.join(nums)
        # Check if all numbers are 0
        return '0' if largest_num[0] == '0' else largest_num
        