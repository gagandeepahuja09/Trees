/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder(TreeNode* A, int& v1, int& v2, int& prev, bool& first) {
    if(!A)
        return;
    inorder(A -> left, v1, v2, prev, first);
    if(A -> val < prev) {
        if(first) {
            v1 = prev;
            v2 = A -> val;
            first = false;
        }
        else {
            v2 = A -> val;
        }
    }
    prev = A -> val;
    inorder(A -> right, v1, v2, prev, first);
}
 
vector<int> Solution::recoverTree(TreeNode* A) {
    int v1 = -1, v2 = -1;
    int prev = INT_MIN;
    bool first = true;
    inorder(A, v1, v2, prev, first);
    vector<int> v;
    v.push_back(v1);
    v.push_back(v2);
    sort(v.begin(), v.end());
    return v;
}

