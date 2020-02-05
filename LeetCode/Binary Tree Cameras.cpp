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
    int nCamera = 0;
    pair<bool, bool> dfs(TreeNode* root) {
        if(!root) {
            return { false, true };
        }
        int monitored = false, hasCamera = false;
        auto l = dfs(root -> left), r = dfs(root -> right);
        if(l.first || r.first)
            monitored = true;
        if(!l.second || !r.second) {
            hasCamera = true;
            monitored = true;
            nCamera++;
        }
        return { hasCamera, monitored };
    }
    
    // Greedy => Put camera only when needed => when any of its child is not being monitored
    int minCameraCover(TreeNode* root) {
        auto ans = dfs(root);
        if(!ans.second)
            nCamera++;
        return nCamera;
    }
};
