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
    int get_len(ListNode* a) {
        ListNode* list = a;
        int len = 0;
        while (list != nullptr) {
            len += 1;
            list = list->next;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = get_len(l1);
        int m = get_len(l2);
        stack<int> s;
        ListNode* temp1;
        ListNode* temp2;
        int first, second;
        if (n >= m) {
            temp1 = l1;
            temp2 = l2;
            first = n - m;
            second = n;
        } else {
            temp1 = l2;
            temp2 = l1;
            first = m - n;
            second = m;
        }
        for (int i = 0; i < first; ++i) {
            s.push(temp1->val);
            temp1 = temp1->next;
        }

        for (int i = first; i < second; ++i) {
            s.push(temp1->val + temp2->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        int carry = 0;
        int val = s.top();
        stack<int> res;
        if (s.top() >= 10) {
            carry = 1;
            val %= 10;
        }
        res.push(val);
        s.pop();
        while (!s.empty()) {
            val = s.top();
            val += carry;
            if (val >= 10) {
                val %= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res.push(val);
            s.pop();
        }
        ListNode* ans;
        if (carry) {
            ans = new ListNode(1);
        } else {
            ans = new ListNode(res.top());
            res.pop();
        }
        ListNode* cur = ans;
        while (!res.empty()) {
            ListNode* temp = new ListNode(res.top());
            res.pop();
            cur->next = temp;
            cur = cur->next;
        }
        return ans;
    }
};
