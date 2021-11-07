class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_dict = collections.defaultdict(list)
        for idx, num in enumerate(nums):     
            nums_dict[num].append(idx)
            value = target - num
            if value in nums_dict:
                if idx != nums_dict[value][0]:
                    return [idx, nums_dict[value][0]]
                elif len(nums_dict[value]) > 1:
                    return [idx, nums_dict[value][1]]
        return [-1, -1]