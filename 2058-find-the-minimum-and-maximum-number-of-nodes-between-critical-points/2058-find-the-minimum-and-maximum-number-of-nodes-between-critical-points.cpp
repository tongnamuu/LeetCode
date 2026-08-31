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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2, -1);
        vector<int>idxs;
        int i = 1;
        int prev = head -> val;
        ListNode* cur = head -> next;
        while(cur!=nullptr && cur->next != nullptr) {
            int now = cur -> val;
            int next = cur -> next -> val;
            if(now<next&&now<prev) {
                idxs.push_back(i);
            } else if(now>next && now > prev) {
                idxs.push_back(i);
            }
            i++;
            prev = now;
            cur = cur -> next;
        }
        if(idxs.size()<=1) return ans;
        ans[1] = idxs.back() - idxs.front();
        ans[0] = idxs[1] - idxs[0];
        for(int i=1;i<idxs.size();i++) {
            ans[0] = min(ans[0], idxs[i]-idxs[i-1]);
        }
        return ans;
    }
};