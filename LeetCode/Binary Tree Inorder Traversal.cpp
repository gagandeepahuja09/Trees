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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        vector<int> ret;
        // Logic => Go as left as possible and keep on pushing the root
        // If no left possible now pop it, add it to answer and change curr to its right
        while(!stk.empty() || curr) {
            if(curr) {
                stk.push(curr);
                curr = curr -> left;
            }
            else {
                TreeNode * tp = stk.top();
                stk.pop();
                ret.push_back(tp -> val);
                curr = tp -> right;
            }
        }
        return ret;
    }
};
