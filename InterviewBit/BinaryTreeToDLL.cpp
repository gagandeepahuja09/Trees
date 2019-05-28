/*

Given a binary tree convert it into circular doubly linked list based on the following rules:

    The left and right pointers in nodes are to be used as previous and next pointers respectively in converted Circular Linked List.

    The order of nodes in List must be same as Inorder of the given Binary Tree.

    The first node of Inorder traversal must be the head node of the Circular List.


Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

TreeNode* concat(TreeNode *l, TreeNode *r) {
    if(!l)
        return r;
    if(!r)
        return l;
    TreeNode *lLast = l -> left;
    TreeNode *rLast = r -> left;
    lLast -> right = r;
    r -> left = lLast;
    l -> left = rLast;
    rLast -> right = l;
    return l;
}

TreeNode* solve(TreeNode *A) {
    if(!A)
        return NULL;
    TreeNode *l = solve(A -> left);
    TreeNode *r = solve(A -> right);
    A -> left = A;
    A -> right = A;
    return concat(concat(l, A), r);
}

