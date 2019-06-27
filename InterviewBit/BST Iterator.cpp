/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> stk;

BSTIterator::BSTIterator(TreeNode *root) {
    while(!stk.empty()) {
        stk.pop();
    }
    while(root) {
        stk.push(root);
        root = root -> left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return stk.size();
}

/** @return the next smallest number */
int BSTIterator::next() {
    if(stk.empty())
        return -1;
    TreeNode* t = stk.top();
    stk.pop();
    int num = t -> val;
    if(t -> right) {
        t = t -> right;
        while(t) {
            stk.push(t);
            t = t -> left;
        }
    }
    return num;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

