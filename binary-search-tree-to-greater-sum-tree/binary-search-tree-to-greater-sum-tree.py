# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def solve(node):
            nonlocal val
            if not node:
                return
            if node.right:
                solve(node.right)
        
            val += node.val;
            node.val = val;
        
            if node.left:
                solve(node.left)
        val = 0
        solve(root)
        return root
        