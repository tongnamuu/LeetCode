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
    ListNode* rev(ListNode* node) {
        if(node->next!=nullptr){
            ListNode* nxt = node->next;
            node->next = nullptr;
            ListNode* head = rev(nxt);
            nxt->next = node;
            return head;
        }
        return node;
    }
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return rev(head);
    }
};
