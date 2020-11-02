# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        val = 0
        node = head
        while node is not None:
            val*=2
            val += node.val
            node = node.next
        return val
