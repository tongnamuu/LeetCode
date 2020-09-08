# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        def get_sum(root, value):
            if root is None:
                return 0
                return int(value, 2)
            if root.val:
                value += "1"
            else:
                value += "0"
            if not root.left and not root.right:
                return int(value, 2)
            return get_sum(root.left, value) + get_sum(root.right, value)

        ans = get_sum(root, "")
        return ans
