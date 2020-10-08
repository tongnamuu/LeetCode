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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* last = head;
        int cnt = 1;
        while(last->next!=nullptr) {
            last = last->next;
            ++cnt;
        }
        last->next = head;
        k%=cnt;
        k = cnt - k;
        ListNode* start = head;
        while(k--){
            start = start->next;
            last = last->next;
        }
        last->next = nullptr;
        return start;
    }
};
