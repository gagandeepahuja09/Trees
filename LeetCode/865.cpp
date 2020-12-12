/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair <int, TreeNode* > lcaHelper(TreeNode* root) {
        if (!root) {
            return { 0, root };
        }
        auto leftLCA = lcaHelper(root -> left);
        auto rightLCA = lcaHelper(root -> right);
        int leftDepth = leftLCA.first;
        int rightDepth = rightLCA.first;
        int depth = max(leftLCA.first, rightLCA.first) + 1;
        TreeNode* lcaNode = NULL;
        if (leftDepth == rightDepth) {
            lcaNode = root;
        } else if (leftDepth > rightDepth) {
            lcaNode = leftLCA.second;
        } else {
            lcaNode = rightLCA.second;
        }
        return { depth, lcaNode };
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcaHelper(root).second;
    }
};
