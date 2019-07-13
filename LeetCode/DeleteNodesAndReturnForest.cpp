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
    TreeNode* delTree(TreeNode* root, unordered_set<int>& s, bool isRoot, vector<TreeNode*>& ret) {
        if(!root)
            return root;
        if(s.count(root -> val) == 0 && isRoot)
            ret.push_back(root);
        bool d = s.count(root -> val);
        root -> left = delTree(root -> left, s, d, ret);
        root -> right = delTree(root -> right, s, d, ret);
        return d ? NULL : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDel) {
        unordered_set<int> s;
        for(auto &x : toDel)
            s.insert(x);
        vector<TreeNode*> ret;
        delTree(root, s, true, ret);
        return ret;
    }
};
