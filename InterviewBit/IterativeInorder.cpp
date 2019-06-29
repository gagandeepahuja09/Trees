/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> stk;
    vector<int> ret;
    TreeNode* curr = A;
    while(1) {
        while(curr) {
            stk.push(curr);
            curr = curr -> left;
        }
        if(stk.empty())
            break;
        TreeNode* t = stk.top();
        stk.pop();
        ret.push_back(t -> val);
        if(t -> right) {
            curr = t -> right;
        }
    }
    return ret;
}

