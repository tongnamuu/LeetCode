# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def pathSum(self, root: TreeNode, targetSum: int) -> List[List[int]]:
        def solve(node, target, cur, ans):
            if node is None:
                return
            if node.left is None and node.right is None and node.val == target:
                cur.append(node.val)
                ans.append(copy.deepcopy(cur))
                cur.pop()
                return
            target -= node.val
            cur.append(node.val)
            solve(node.left, target, cur, ans)
            solve(node.right, target, cur, ans)
            cur.pop()
        ans = []
        cur = []
        solve(root, targetSum, cur, ans)
        return ans
