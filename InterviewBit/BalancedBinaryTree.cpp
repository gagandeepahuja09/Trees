/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
pair<bool, int> balance(TreeNode *A) {
    if(!A) {
        return { true, 0 };
    }
    pair<bool, int> l = balance(A -> left);
    pair<bool, int> r = balance(A -> right);
    bool ans = false;
    int lh = l.second, rh = r.second;
    if(abs(lh - rh) <= 1 && l.first && r.first)
        ans = true;
    return { ans, max(lh, rh) + 1 };    
}
 
int Solution::isBalanced(TreeNode* A) {
    return balance(A).first;
}

