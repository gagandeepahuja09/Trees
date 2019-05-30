/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* prune(TreeNode* root, int k, int sum) {
    if(!root)
        return NULL;
    root -> left = prune(root -> left, k, sum + root -> val);
    root -> right = prune(root -> right, k, sum + root -> val);
    if(!root -> left && !root -> right && sum + root -> val < k) {
        free(root);
        return NULL;
    }
    return root;
}
 
TreeNode* Solution::solve(TreeNode* A, int B) {
    return prune(A, B, 0);
}

