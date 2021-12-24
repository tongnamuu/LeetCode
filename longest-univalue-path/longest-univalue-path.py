# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        def solve(node):
            if node is None:
                return 0
            x = solve(node.left)
            y = solve(node.right)
            if node.left and node.left.val == node.val:
                x += 1
            else:
                x = 0
            if node.right and node.right.val == node.val:
                y += 1
            else:
                y = 0
            nonlocal ans
            ans = ans if ans > x + y else x + y
            return x if x > y else y
        ans = 0
        solve(root)
        return ans