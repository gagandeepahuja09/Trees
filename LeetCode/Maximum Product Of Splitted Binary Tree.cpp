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
    vector<int> pre, suff;
    int sum, total, ans;
    
    void normal(TreeNode* root) {
        if(!root)
            return;
        total += root -> val;
        normal(root -> left);
        normal(root -> right);
    }
    
    int sumUnder(TreeNode* root) {
        if(!root)
            return 0;
        int l = sumUnder(root -> left);
        int r = sumUnder(root -> right);
        ans = max(ans, max(l * (total - l), r * (total - r)));
        return l + r + root -> val;
    }
    
    int maxProduct(TreeNode* root) {
        sum = total = ans = 0;
        normal(root);
        sumUnder(root);
        return ans;
    }
};
