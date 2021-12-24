# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        def solve(node):
            if node is None:
                return 0
            x = solve(node.left) + 1
            y = solve(node.right) + 1
            return x if x > y else y
        return solve(root)