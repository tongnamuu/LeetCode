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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> x;
        for(int i : nums) {
            x.insert(i);
        }
        while(head!=nullptr) {
            if(x.find(head -> val) != x.end()) {
                head = head -> next;
            } else {
                break;
            }
        }
        if(head==nullptr) return head;
        ListNode* result = head;
        ListNode* before = head;
        ListNode* cur = head -> next;
        while(cur!=nullptr) {
            if(x.find(cur -> val) != x.end()) {
                before -> next = cur -> next;
                cur = cur -> next;
            } else {
                before = cur;
                cur = cur -> next;
            }
        }
        return result;
    }
};