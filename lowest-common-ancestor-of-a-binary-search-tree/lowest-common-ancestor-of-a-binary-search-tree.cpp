/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(root==a) return a;
        if(root==b) return b;
        if(root->right && root->left) {
            if(root->val > a->val && root->val < b->val) return root;
        }
        if(root->val < a->val) return find(root->right, a, b);
        if(root->val > b->val) return find(root->left, a, b);
        return find(root, a, b);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) return find(root, q, p);
        return find(root, p, q);
    }
};
