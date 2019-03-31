/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void flattenHelper(TreeNode* A) {
    if(!root || (!(root -> left) && !(root -> right))
        return;
    if(root -> left) {
        flatten(root -> left);
        TreeNode* temp = root -> right;
        root -> right = root -> left;
        root -> left = NULL;
        TreeNode* t = root -> right;
        while(t -> right) {
            
        }
    }    
} 
 
TreeNode* Solution::flatten(TreeNode* A) {
    flattenHelper(A);
    return A;
}

