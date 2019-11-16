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
    unordered_map<string, vector<TreeNode*>> subTree;
    unordered_set<TreeNode*> ret;
    
    string findDup(TreeNode* root) {
        if(!root)
            return "_";
        string l = findDup(root -> left);
        string r = findDup(root -> right);
        string curr = "(" + l + to_string(root -> val) + "$" + r + ")";
        subTree[curr].push_back(root);
        return curr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        findDup(root);
        vector<TreeNode*> ret;
        for(auto x : subTree) {
            if(x.second.size() > 1) {
                ret.push_back(x.second[0]);
            }
        }
        return ret;
    }
};
