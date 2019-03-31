/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void pathSumHelper(TreeNode* A, int B, vector<vector<int>>& res, 
vector<int> v) {
    if(!A) {
        return;
    }
    if(!(A -> left) && !(A -> right)) {
        if(B == A -> val) {
            v.push_back(A -> val);
            res.push_back(v);
        }
        return;    
    }
    vector<int> v1 = v;
    v1.push_back(A -> val);
    pathSumHelper(A -> left, B - A -> val, res, v1);
    pathSumHelper(A -> right, B - A -> val, res, v1);
} 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> v;
    pathSumHelper(A, B, res, v);
    return res;
}

