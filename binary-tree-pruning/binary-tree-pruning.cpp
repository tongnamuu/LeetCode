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
    bool ok(TreeNode* node) {
        if(!node) return false;
        bool l = ok(node->left);
        if(!l) node->left = nullptr;
        bool r = ok(node->right);
        if(!r) node->right = nullptr;
        return node->val == 1 || l||r;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!ok(root)) return nullptr;
        return root;
    }
};
