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
    
    bool flip(TreeNode* root, vector<int>& v, int &i, vector<int>& ret) {
        if(!root) {
            return true;
        }
        if(root -> val != v[i++])
            return false;
        if(root -> left && root -> left -> val != v[i]) {
            ret.push_back(root -> val);
            return flip(root -> right, v, i, ret) && flip(root -> left, v, i, ret);
        }
        return flip(root -> left, v, i, ret) && flip(root -> right, v, i, ret);
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ret;
        int i = 0;
        if(!flip(root, voyage, i, ret))
            return { -1 };
        return ret;
    }
};
