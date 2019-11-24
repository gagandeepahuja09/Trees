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
    TreeNode* f(TreeNode* root, int d, int v) {
        if(!root)
            return root;
        if(d == 2) {
            TreeNode *l = new TreeNode(v);
            l -> left = f(root -> left, d - 1, v);
            TreeNode *r = new TreeNode(v);
            r -> right = f(root -> right, d - 1, v);
            root -> left = l;
            root -> right = r;
            return root;
        }
        root -> left = f(root -> left, d - 1, v);
        root -> right = f(root -> right, d - 1, v);
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode *temp = new TreeNode(v);
            temp -> left = root;
            return temp;
        }
        return f(root, d, v);
    }
};
