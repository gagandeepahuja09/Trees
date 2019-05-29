/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* build(vector<int> &pre, vector<int> &in, int pStart, 
int pEnd, int inStart, int inEnd, unordered_map<int, int> &mp) {
    if(pStart > pEnd) {
        return NULL;
    }
    TreeNode *root = new TreeNode(pre[pStart]);
    int idx = mp[pre[pStart]];
    root -> left = build(pre, in, pStart + 1, pStart + (idx - inStart), inStart, idx - 1, mp);
    root -> right = build(pre, in, pStart + (idx - inStart) + 1, pEnd, idx + 1, inEnd, mp);
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &pre, vector<int> &in) {
    unordered_map<int, int> mp;
    for(int i = 0; i < in.size(); i++) {
        mp[in[i]] = i;
    }
    return build(pre, in, 0, pre.size() - 1, 0, in.size() - 1, mp);
}

