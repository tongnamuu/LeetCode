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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> get_arr(ListNode* head){
        vector<int>res;
        ListNode* node = head;
        while(node!=nullptr){
            res.push_back(node->val);
            node =node->next;
        }
        return res;
    }
    TreeNode* insert(const vector<int>& a, int s, int e) {
        if(s>e) return nullptr;
        if(s==e) {
            return new TreeNode(a[s]);
        }
        int m = s + e >> 1;
        TreeNode* x = new TreeNode(a[m]);
        x->left = insert(a, s, m - 1);
        x->right = insert(a, m+1, e);
        return x;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>a = get_arr(head);
        int n = a.size();
        return insert(a, 0, n-1);
    }
};
