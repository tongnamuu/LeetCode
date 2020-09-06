# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def _get_all_elem(root, elem_list):
            if root is None:
                return
            _get_all_elem(root.left, elem_list)
            elem_list.append(root.val)
            _get_all_elem(root.right, elem_list)

        ans = []
        _get_all_elem(root1, ans)
        _get_all_elem(root2, ans)
        ans.sort()
        return ans

