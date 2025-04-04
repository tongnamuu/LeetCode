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
    struct Tree {
        int val;
        Tree* left;
        Tree* right;
        Tree* parent;
        TreeNode* node;
        int depth;
    };
    int maxDepth;
    Tree* dfs(TreeNode* root, int depth) {
        if(root==nullptr) return nullptr;
        Tree* tree = new Tree();
        maxDepth = max(maxDepth, depth);
        tree -> val = root -> val;
        tree -> depth = depth;
        tree -> node = root;
        if(root->left != nullptr) {
            Tree* left = dfs(root ->left, depth+1);
            tree -> left = left;
            left -> parent = tree;
        }
        if(root->right != nullptr) {
             Tree* right = dfs(root->right, depth+1);
             tree -> right = right;
             right -> parent = tree;
        }
        return tree;
    }
    void dfs2(Tree* root, vector<Tree*>& nodes) {
        if(root==nullptr) return;
        if(root -> depth == maxDepth) {
            nodes.push_back(root);
        }
        dfs2(root->left, nodes);
        dfs2(root->right, nodes);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        Tree* myroot = dfs(root, 1);
        vector<Tree*> nodes;
        dfs2(myroot, nodes);
        if(nodes.size() == 1) {
            return nodes[0] -> node;
        }
        while(1) {
            Tree* x = nodes[0];
            bool allSame = true;
            for(int i=0;i<nodes.size();i++) {
                if(x != nodes[i]) {
                    allSame = false;
                    break;
                }
            }
            for(Tree*& i : nodes) {
                if(i!=x) {
                    allSame = false;
                    break;
                }
            }
            if(allSame) break;
            for(int i=0;i<nodes.size();i++) {
                nodes[i] = nodes[i] -> parent;
            }
        }
        return nodes[0] -> node;
    }
};