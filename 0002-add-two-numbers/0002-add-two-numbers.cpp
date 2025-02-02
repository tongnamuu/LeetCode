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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        int val = 0;
        int carry = 0;
        ListNode* cur = head;
        while(l1!=nullptr && l2!=nullptr) {
            val = (l1 -> val + l2 -> val + carry) % 10;
            carry = (l1 -> val + l2 -> val + carry) / 10;
            ListNode* node = new ListNode(val);
            cur -> next = node;
            l1 = l1 -> next;
            l2 = l2 -> next;
            cur = node;
        }
        while(l1!=nullptr) {
            val = (l1->val + carry) % 10;
            carry = (l1 -> val + carry) / 10;
            ListNode* node = new ListNode(val);
            cur -> next = node;
            l1 = l1 -> next;
            cur = node;
        }
        while(l2!=nullptr) {
             val = (l2->val + carry) % 10;
            carry = (l2 -> val + carry) / 10;
            ListNode* node = new ListNode(val);
            cur -> next = node;
            l2 = l2 -> next;
            cur = node;
        }
        if(carry) {
             ListNode* node = new ListNode(carry);
             cur -> next = node;
        }
        return head -> next;
    }
};