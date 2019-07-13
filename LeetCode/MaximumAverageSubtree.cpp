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
    double mx;
    pair<double, pair<int, int>> maxSub(TreeNode* root) {
        if(!root)
            return { 0.0, { 0, 0 } };
        auto l = maxSub(root -> left);
        auto r = maxSub(root -> right);
        int ele = l.second.second + r.second.second + 1;
        int sum = l.second.first + r.second.first + root -> val;
        double avg = (double)sum / (double)ele;
        mx = max(mx, avg);
        // cout << sum << " " << ele << " " << avg << endl;
        return { avg, { sum, ele } };
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        mx = 0;
        maxSub(root);
        return mx;
    }
};
