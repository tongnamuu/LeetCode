# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def construct(nums, s, e):
            if s > e:
                return None
            m = s + (e - s) // 2
            x = TreeNode(nums[m])
            x.left = construct(nums, s, m - 1)
            x.right = construct(nums, m + 1 , e)
            return x
        return construct(nums, 0, len(nums) - 1)
