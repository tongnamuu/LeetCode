# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None:
            return TreeNode(val)
        start = root
        while True:
            if root.val < val:
                if root.right is None:
                    root.right = TreeNode(val)
                    break
                root = root.right
            else:
                if root.left is None:
                    root.left = TreeNode(val)
                    break
                root = root.left
        return start
