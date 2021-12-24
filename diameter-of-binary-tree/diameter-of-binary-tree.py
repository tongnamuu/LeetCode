# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def solve(node):
            if node is None:
                return 0
            x = solve(node.left)
            y = solve(node.right)
            nonlocal ans
            if x + y > ans:
                ans = x + y
            return x + 1 if x > y else y + 1
        ans = 0
        left = solve(root.left)
        right = solve(root.right)
        return max(ans, left + right)
            