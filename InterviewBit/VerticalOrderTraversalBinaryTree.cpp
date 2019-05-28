/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, vector<int>> mp;
    vector<vector<int>> ret;
    queue<pair<int, TreeNode*>> q;
    if(!A)
        return ret;
    q.push({ 0, A });
    while(!q.empty()) {
        pair<int, TreeNode*> p = q.front();
        q.pop();
        TreeNode* root = p.second;
        mp[p.first].push_back(root -> val);
        if(root -> left) {
            q.push({ p.first - 1, root -> left });
        }
        if(root -> right) {
            q.push({ p.first + 1, root -> right });
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++) {
        vector<int> v = it -> second;
        ret.push_back(v);
    }
    return ret;
}

