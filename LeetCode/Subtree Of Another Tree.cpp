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
    bool isSameTree(TreeNode* s, TreeNode* t) {
       if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        return (s -> val == t -> val) && isSameTree(s -> left, t -> left) && isSameTree(s -> right, t -> right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t)
            return true;
        if(!s || !t)
            return false;
        return isSameTree(s, t) || isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }
};

// O(N + M)
class Solution {
public:
    bool ans = false;
    string st;
    string f(TreeNode* root, bool ok) {
        if(!root)
            return "_";
        string curr =  "(" + f(root -> left, ok) + "." + to_string(root -> val) + "." + f(root -> right, ok) + ")";
        if(st == curr)
            ans = true;
        return curr;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        st = f(t, 0);
        f(s, 1);
        return ans;
    }
};
