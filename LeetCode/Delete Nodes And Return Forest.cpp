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
    vector<TreeNode*> ret;
    unordered_set<int> st;
    void f(TreeNode* &root) {
        if(!root)
            return;
        f(root -> left);
        f(root -> right);
        if(st.count(root -> val)) {
            if(root -> left)
                ret.push_back(root -> left);
            if(root -> right)
                ret.push_back(root -> right);
            root = NULL;
            delete root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
         for(int i = 0; i < toDelete.size(); i++)
             st.insert(toDelete[i]);
        f(root);
        if(root)
            ret.push_back(root);
        return ret;
    }
};
