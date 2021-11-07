# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head;
        E = head;
        O = head.next;
        t = O;
        if not O:
            return head;
        while True:
            E.next = O.next;
            E = E.next;
            if not E:
                break;
            O.next = E.next;
            O = O.next;
            if not O:
                break;
        
        temp = head;
        while temp.next:
            temp = temp.next
    
        temp.next = t;
        return head;