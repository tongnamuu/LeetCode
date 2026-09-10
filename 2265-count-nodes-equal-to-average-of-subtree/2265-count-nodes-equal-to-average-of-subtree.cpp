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
    pair<int, int> solve(TreeNode* node, int& ans) {
        if(node==nullptr) {
            return {0, 0};
        }
        pair<int,int> l = solve(node->left, ans);
        pair<int,int> r = solve(node->right, ans);
        int cnt = l.first + r.first+1;
        int sum = l.second + r.second + node->val;
        if(sum/cnt==node->val) {
            ans++;
        }
        return {cnt, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};