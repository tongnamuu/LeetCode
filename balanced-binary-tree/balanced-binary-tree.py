# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def get_height(node):
            if not node:
                return 0
            x = get_height(node.left)
            if x == -1:
                return -1
            y = get_height(node.right)
            if y == -1:
                return -1
            if abs(x-y) > 1:
                return -1
            return x + 1 if x > y else y + 1
        val = get_height(root)
        return val != -1