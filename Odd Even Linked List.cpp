/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* E = head;
        ListNode* O = head->next;
        ListNode* t = O;
        if (!O) return head;
        while (1) {
            E->next = O->next;
            E = E->next;
            if (!E) break;
            O->next = E->next;
            O = O->next;
            if (!O) break;
        }
        ListNode* temp = head;
        for (; temp->next; temp = temp->next)
            ;
        temp->next = t;
        return head;
    }
};