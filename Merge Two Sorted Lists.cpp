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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* x = ans;
        while (a && b) {
            if (a->val < b->val) {
                ans->next = a;
                a = a->next;
                ans = ans->next;
            } else {
                ans->next = b;
                b = b->next;
                ans = ans->next;
            }
        }
        if (a) {
            ans->next = a;
        }
        if (b) {
            ans->next = b;
        }
        ans = x->next;
        return ans;
    }
};