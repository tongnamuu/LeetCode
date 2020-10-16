# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        x = head
        v = []
        while x is not None:
            v.append(x.val)
            x = x.next
        v.sort()
        x = head
        idx = 0
        while x is not None:
            x.val = v[idx]
            idx += 1
            x = x.next
        return head
