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
    void f(TreeNode* root, string curr, string& mn) {
        if(!root)
            return;
        if(!root -> left && !root -> right) {
            curr = (char)(root -> val + 'a') + curr;
            if(!mn.size())
                mn = curr;
            else
                mn = min(mn, curr);
        }
        f(root -> left, (char)(root -> val + 'a') + curr, mn);
        f(root -> right, (char)(root -> val + 'a') + curr, mn);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(!root)
            return "";
        string mn = "";
        f(root, "", mn);
        return mn;
    }
};

