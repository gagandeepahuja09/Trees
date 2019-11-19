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
    bool f(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        return (s -> val == t -> val && ((f(s -> left, t -> left) && f(s -> right, t -> right)) || 
                (f(s -> left, t -> right) && f(s -> right, t -> left))) );
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return f(root1, root2);
    }
};
