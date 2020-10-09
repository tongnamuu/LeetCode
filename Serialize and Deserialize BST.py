# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        if not root:
            return ''
        return str(root.val)+' '+ self.serialize(root.left) + ' ' + self.serialize(root.right)
        

    def deserialize(self, data: str) -> TreeNode:
        val_list = list(map(int, data.split()))
        def _deserialize(s, e):
            if s > e:
                return None
            if e == s:
                return TreeNode(val_list[s])
            idx = e + 1
            val = val_list[s]
            for i in range(s, e+1):
                if val_list[i] > val:
                    idx = i
                    break
            temp = TreeNode(val)
            temp.left = _deserialize(s + 1, idx - 1)
            temp.right = _deserialize(idx, e)
            return temp
        return _deserialize(0, len(val_list) - 1)
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
