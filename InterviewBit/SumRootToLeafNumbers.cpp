/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void sumNumbersUtil(TreeNode* A, int val, int& ans) {
    if(!A)
        return;
    if(!(A -> left) && !(A -> right)) {
        ans = (ans%1003 + (val * 10 + A -> val)%1003);
        return;
    }
    sumNumbersUtil(A -> left,  
    ((val%1003 * 10)%1003 + A -> val%1003)%1003, ans);
    sumNumbersUtil(A -> right, 
    ((val%1003 * 10)%1003 + A -> val%1003)%1003, ans);
} 
 
int Solution::sumNumbers(TreeNode* A) {
    int ans = 0;
    sumNumbersUtil(A, 0, ans);
    return ans%1003;
}

