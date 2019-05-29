/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

pair<bool, int> balanceHeight(TreeNode* A) {
    if(!A) {
        return { true, 0 };
    }
    pair<bool, int> l = balanceHeight(A -> left);
    pair<bool, int> r = balanceHeight(A -> right);
    bool ans = true;
    if((!l.first || !r.first) || (abs(l.second - r.second) > 1))
        ans = false;
    int h = max(l.second, r.second) + 1;
    return { ans, h };
} 
 
int Solution::isBalanced(TreeNode* A) {
    return balanceHeight(A).first;
}

