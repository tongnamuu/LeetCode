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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        stack<TreeNode*> s;
        s.push(root);
        int ans = 0;
        while (!s.empty()) {
            TreeNode* now = s.top();
            s.pop();
            int val = now->val;
            if (val >= low && val <= high) ans += val;
            if (now->left) s.push(now->left);
            if (now->right) s.push(now->right);
        }
        return ans;
    }
};
