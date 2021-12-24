# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def cal(self, x, y):
        if not x and not y:
            return None
        if not x:
            return TreeNode(y.val)
        if not y:
            return TreeNode(x.val)
        return TreeNode(x.val + y.val)
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        ans = self.cal(root1, root2)
        q = deque()
        q.append((ans, root1, root2))
        while q:
            now, x, y = q.popleft()
            if now is None:
                continue
            now.left = self.cal(x.left if x is not None else None, y.left if y is not None else None)
            now.right = self.cal(x.right if x is not None else None, y.right if y is not None else None)
            q.append((now.left, x.left if x is not None else None, y.left if y is not None else None))
            q.append((now.right, x.right if x is not None else None, y.right if y is not None else None))
        return ans
        