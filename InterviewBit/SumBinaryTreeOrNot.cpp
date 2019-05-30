/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

pair<bool, int> sumTree(TreeNode* root) {
    if(!root) {
        return { true, 0 };
    }
    pair<bool, int> l = sumTree(root -> left);
    pair<bool, int> r = sumTree(root -> right);
    bool ans = true;
    if((root -> val != l.second + r.second && (root -> left || root -> right)) || !l.first || !r.first) 
        ans = false;
    return { ans, root -> val + l.second + r.second };    
} 
 
int Solution::solve(TreeNode* A) {
    return sumTree(A).first;
}

