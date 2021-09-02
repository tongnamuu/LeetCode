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
    TreeNode* insert(TreeNode* node, int val) {
        if(node==nullptr) {
            node = new TreeNode(val);
            return node;
        }
        if(node->val < val) {
            node->right = insert(node->right, val);
        } else{
            node->left = insert(node->left, val);
        }
        return node;
    }
    bool isSame(TreeNode* a, TreeNode* b) {
        if(!a && b) return false;
        if(a && !b) return false;
        if(!a && !b) return true;
        if(a->val==b->val) {
            return isSame(a->left, b->left) && isSame(a->right, b->right);
        }
        return false;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int> num(n);
        for(int i=0;i<n;++i) num[i] = i + 1;
        vector<TreeNode*>ans;
        do{
            TreeNode* root = new TreeNode(num[0]);
            for(int i=1;i<n;++i) {
                insert(root, num[i]);
            }
            bool addable = true;
            for(auto& r : ans) {
                if(isSame(r, root)){
                    addable = false;
                    break;
                }
            }
            if(addable) ans.push_back(root);
        }while(next_permutation(num.begin(), num.end()));
        return ans;
    }
};
