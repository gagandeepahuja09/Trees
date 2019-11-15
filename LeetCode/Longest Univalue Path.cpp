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
    int uniPath(TreeNode* root, int& mx) {
        if(!root)
           return 0;
        int l = uniPath(root -> left, mx), r = uniPath(root -> right, mx);
        l = (root -> left && root -> left -> val == root -> val) ? l + 1 : 0;
        r = (root -> right && root -> right -> val == root -> val) ? r + 1 : 0;
        mx = max(mx, l + r);
        return max(l, r);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int mx = 0;
        uniPath(root, mx);
        return mx;
    }
};
