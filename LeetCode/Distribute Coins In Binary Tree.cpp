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
    int moves = 0;
    int moveCoins(TreeNode* root) {
        if(!root)
            return 0;
        int l = moveCoins(root -> left), r = moveCoins(root -> right);
        moves += abs(l) + abs(r);
        return root -> val + l + r - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        moveCoins(root);
        return moves;
    }
};
