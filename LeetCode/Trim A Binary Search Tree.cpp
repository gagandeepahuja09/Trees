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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return root;
        TreeNode* l = trimBST(root -> left, L, R);
        TreeNode* r = trimBST(root -> right, L, R);
        if(root -> val > R) {
            root = l;
        }
        else if(root -> val < L) {
            root = r;
        }
        else {
            root -> left = l;
            root -> right = r;
        }
        return root;
    }
};
