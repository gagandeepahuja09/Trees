/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MOD 1000000007

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if(!root)
            return 0;
        val = (val * 2 + root -> val) % MOD;
        return (root -> left == root -> right ? val : sumRootToLeaf(root -> left, val) + sumRootToLeaf(root -> right, val));
    }
};
