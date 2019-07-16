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
    int mx = 0;
    pair<int,  int> maxDiff(TreeNode* root) {
        if(!root)
            return { -1, INT_MAX };
        auto l = maxDiff(root -> left);
        auto r = maxDiff(root -> right);
        if(l.first != -1)
            mx = max(mx, abs(root -> val - l.first)); 
        if(l.second != INT_MAX)
            mx = max(mx, abs(root -> val - l.second));
        if(r.first != -1)
            mx = max(mx, abs(root -> val - r.first));
        if(r.second != INT_MAX)
            mx = max(mx, abs(root -> val - r.second));
        int maxN  = max(r.first, max(l.first, root -> val));
        int minN  = min(r.second, min(l.second, root -> val));
        return { maxN, minN };
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff(root);
        return mx;
    }
};
