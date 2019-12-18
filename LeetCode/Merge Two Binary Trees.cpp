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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) {
            return NULL;
        }
        int v = (t1 ? t1 -> val : 0) + (t2 ? t2 -> val : 0);
        TreeNode* root = new TreeNode(v);
        root -> left = mergeTrees(t1 ? t1 -> left : t1, t2 ? t2 -> left : t2);
        root -> right = mergeTrees(t1 ? t1 -> right : t1, t2 ? t2 -> right : t2);
        return root;
    }
};
