# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        
        def insert(val: int, cur: ListNode) -> ListNode:
            head = cur
            if cur.val > val:
                insert_node = ListNode(val, cur)
                return insert_node
            prev = cur
            cur = cur.next    
            while cur is not None:
                if cur.val > val:
                    insert_node = ListNode(val, cur)
                    prev.next = insert_node
                    return head
                prev = cur
                cur = cur.next
            prev.next = ListNode(val)
            return head
                    
        node = head.next
        cur = ListNode(head.val)
        while node is not None:
            x = node.val
            cur = insert(x, cur)
            node = node.next
        return cur
