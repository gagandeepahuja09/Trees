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
    int maxSum = INT_MIN;
    int maxPath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftMaxPath = maxPath(root -> left);
        int rightMaxPath = maxPath(root -> right);
        maxSum = max(maxSum, root -> val + leftMaxPath + rightMaxPath);
        return max(0, root -> val + max(leftMaxPath, rightMaxPath));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
};
