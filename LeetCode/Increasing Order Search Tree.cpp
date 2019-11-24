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
    TreeNode *prev, *nRoot;
    void inorder(TreeNode* root) {
        if(!root)
            return;
        inorder(root -> left);
        if(!prev) {
            prev = root;
            nRoot = root;
        }
        else {
            prev -> left = NULL;
            prev -> right = root;
            prev = root;
            root -> left = NULL;
        }
        inorder(root -> right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        prev = nRoot = NULL;
        inorder(root);
        return nRoot;
    }
};
