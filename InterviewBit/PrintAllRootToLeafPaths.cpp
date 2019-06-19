/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void paths(TreeNode* root, vector<int>& v, vector<vector<int>>& ret) {
    if(!root)
        return;
    if(!root -> left && !root -> right) {
        v.push_back(root -> val);
        ret.push_back(v);
        v.pop_back();
        return;
    }
    v.push_back(root -> val);
    paths(root -> left, v, ret);
    paths(root -> right, v, ret);
    v.pop_back();
} 
 
vector<vector<int> > Solution::solve(TreeNode* A) {
    vector<vector<int>> ret;
    if(!A)
        return ret;
    vector<int> v;
    paths(A, v, ret);
    return ret;
}

