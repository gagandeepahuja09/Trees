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
    while(A || stk.size()) {
        while(A) {
            stk.push(A);
            A = A -> left;
        }
        A = stk.top();
        stk.pop();
        ret.push_back(A -> val);
        A = A -> right;
    }
    return ret;
}

