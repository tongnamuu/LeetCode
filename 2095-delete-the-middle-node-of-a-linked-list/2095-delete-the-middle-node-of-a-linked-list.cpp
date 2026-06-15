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
    ListNode* deleteMiddle(ListNode* head) {
        queue<ListNode*> s;
        ListNode* temp = head;
        while(temp != nullptr) {
            s.push(temp);
            temp = temp ->next;
        }
        int n = s.size();
        if(n==1 || n==0) return nullptr;
        int idx = n / 2;
        ListNode* cur;
        for(int i=0;i<idx;i++) {
            cur = s.front();
            s.pop();
        }
        if (s.empty()) {
            cur -> next = nullptr;
        } else {
            cur -> next = s.front()->next;
        }
        return head;
    }
};