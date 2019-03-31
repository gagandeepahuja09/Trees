/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode* A) {
    if(!A) {
        return 0;
    }
    int l = height(A -> left);
    int r = height(A -> right);
    
    if(l < 0 || r < 0)
        return INT_MIN;
    
    if(abs(l-r) > 1)
        return INT_MIN;
    return 1 + max(l, r);
}

int Solution::isBalanced(TreeNode* A) {
    if(height(A) < 0)
        return 0;
    return 1;    
}

