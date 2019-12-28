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
    int dh;
    int sum;
    void f(TreeNode* root, int d) {
        if(!root)
            return;
        dh = max(dh, d);
        f(root -> left, d + 1);
        f(root -> right, d + 1);
    }
    
    void f2(TreeNode* root, int d) {
        if(!root)
            return;
        if(d == dh)
            sum += root -> val;
        f2(root -> left, d + 1);
        f2(root -> right, d + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dh = sum = 0;
        f(root, 0);
        f2(root, 0);
        return sum;
    }
};
