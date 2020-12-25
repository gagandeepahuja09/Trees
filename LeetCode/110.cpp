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
    pair<int, bool> _isBalanced(TreeNode* root) {
        if (!root) {
            return { 0, true };
        }
        auto leftAns = _isBalanced(root -> left);
        auto rightAns = _isBalanced(root -> right);
        int height = max(leftAns.first, rightAns.first) + 1;
        bool balancedCheck = leftAns.second && rightAns.second 
            && (abs(leftAns.first - rightAns.first) <= 1);
        return { height, balancedCheck };
    }
public:    
    bool isBalanced(TreeNode* root) {
        return _isBalanced(root).second;
    }
};
