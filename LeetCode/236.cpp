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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        TreeNode* leftLCA = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root -> right, p, q);
        if (root == p || root == q)
            return root;
        if (leftLCA && rightLCA) {
            return root;
        }
        else if (leftLCA) {
            return leftLCA;
        }
        return rightLCA;
    }
};
