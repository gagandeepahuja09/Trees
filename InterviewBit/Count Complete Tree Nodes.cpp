int Solution::solve(TreeNode* A) {
    if(!A)
        return 0;
    int hl = 0, hr = 0;
    TreeNode *l = A, *r = A;
    while(l) {
        l = l -> left;
        hl++;
    }
    while(r) {
        r = r -> right;
        hr++;
    }
    if(hl == hr)
        return (1 << hl) - 1;
    return 1 + solve(A -> left) + solve(A -> right);    
}
