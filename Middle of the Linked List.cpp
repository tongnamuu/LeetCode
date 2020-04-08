/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        auto x = head;
        int len = 0;
        while (x != 0) {
            x = x->next;
            ++len;
        }
        len /= 2;
        x = head;
        for (int i = 0; i < len; ++i)
            x = x->next;
        return x;
    }
};