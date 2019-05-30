/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void paths(TreeNode* root, vector<int>& v, vector<vector<int>>& res) {
    if(!root) {
        return;
    }
    v.push_back(root -> val);
    if(!root -> left && !root -> right) {
        res.push_back(v);
    }
    paths(root -> left, v, res);
    paths(root -> right, v, res);
    v.pop_back();
}
 
vector<vector<int> > Solution::solve(TreeNode* A) {
    vector<vector<int>> res;
    vector<int> v;
    paths(A, v, res);
    return res;
}

