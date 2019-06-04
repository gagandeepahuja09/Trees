/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxSum;
 
int maxPath(TreeNode* A) {
    if(!A)
        return 0;
    int maxL = maxPath(A -> left);
    int maxR = maxPath(A -> right);
    maxSum = max(maxSum, (maxL < 0 ? 0 : maxL) + (maxR < 0 ? 0 : maxR) + A -> val);
    return max(0, max(maxL, maxR)) + A -> val;
} 
 
int Solution::maxPathSum(TreeNode* A) {
    maxSum = INT_MIN;
    maxPath(A);
    return maxSum;
}

