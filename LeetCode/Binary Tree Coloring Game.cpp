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
    int left, right, val;
    int count(TreeNode* root) {
        if(!root)
            return 0;
        int l = count(root -> left), r = count(root -> right);
        if(root -> val == val) {
            left = l, right = r;
        }
        return l + r + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        n = count(root);
        return (max(left, max(right, n - left - right - 1)) > n / 2);
    }
};
