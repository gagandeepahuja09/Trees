/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


int lcaHelper(TreeNode* A, int B, int C) {
    if(!A)
        return 0;
    if(A -> val == B || A -> val == C)
        return A -> val;
    int l = lcaHelper(A -> left, B, C);
    int r = lcaHelper(A -> right, B, C);
    if(l && r) {
        return A -> val;
    }
    else if(l)
        return l;
    else if(r)
        return r;
    else
        return 0;
}

bool exists(TreeNode* A, int B) {
    if(!A)
        return 0;
    return ((A -> val == B) || exists(A -> left, B) 
    || exists(A -> right, B));    
} 
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(!exists(A, B) || !exists(A, C))
        return -1;
    return lcaHelper(A, B, C);    
    
}

