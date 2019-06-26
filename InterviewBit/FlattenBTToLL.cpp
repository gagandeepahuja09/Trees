/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
pair<TreeNode*, TreeNode*> flat(TreeNode* root) {
    if(!root) {
        return { NULL, NULL };
    }
    if(!root -> left && !root -> right) {
        return { root, root };
    }
    pair<TreeNode*, TreeNode*> l = flat(root -> left);
    pair<TreeNode*, TreeNode*> r = flat(root -> right);
    root -> left = NULL;
    if(l.first) {
        root -> right = l.first;
        if(l.second)
            l.second -> right = r.first;
    }
    if(r.second)
        return { root, r.second };
    return { root, l.second };    
}
 
TreeNode* Solution::flatten(TreeNode* A) {
    if(!A)
        return A;
    return flat(A).first;
}

