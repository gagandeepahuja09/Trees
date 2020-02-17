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
    vector<TreeNode*> f(int start, int end) {
        vector<TreeNode*> ret;
        if(start >= end) {
            if(start == end)
                ret.push_back(new TreeNode(start));
            else
                ret.push_back(NULL);
            return ret;
        }
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = f(start, i - 1), rights = f(i + 1, end);
            for(TreeNode* l : lefts) {
                for(TreeNode* r : rights) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return f(1, n);
    }
};
