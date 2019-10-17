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
    unordered_map<int, vector<TreeNode*>> cache;
    vector<TreeNode*> f(int n) {
        vector<TreeNode*> ret;
        if(cache[n].size())
            return cache[n];
        if(n == 1) {
            TreeNode* root = new TreeNode(0);
            ret.push_back(root);
            return cache[n] = ret;
        }
        for(int i = 1; i < n; i += 2) {
            int l = i, r = n - i - 1;
            for(TreeNode* left : f(l)) {
                for(TreeNode* right : f(r)) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = left;
                    root -> right = right;
                    ret.push_back(root);
                }
            }
        }
        return cache[n] = ret;
    }
    
    vector<TreeNode*> allPossibleFBT(int N) {
        return f(N);
    }
};
