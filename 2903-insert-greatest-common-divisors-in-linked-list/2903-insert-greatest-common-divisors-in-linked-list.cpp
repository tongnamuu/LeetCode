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
    
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* now = head;
        if (head -> next == nullptr) {
            return head;
        }
        ListNode* next = head -> next;
        while(true) {
            int x = now -> val;
            int y = next -> val;
            int g = gcd(x,y);
            ListNode* node = new ListNode(g, next);
            now -> next = node;
            now = next;
            next = next -> next;
            if(next == nullptr) {
                break;
            }
        }
        return head;
    }
};