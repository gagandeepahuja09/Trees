/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
Smallest Subtree with all the Deepest Nodes

Given a binary tree with root node pointer A . The depth of each node is the shortest distance to the root. A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes of the entire tree lies in its subtree.

Note: All nodes values are uniques in the tree.


Input Format

The only arguments given are root pointer A.

Output Format

Return the node with the largest depth such that it contains all the deepest nodes of the entire tree lies in its subtree.

Constraints

1 <= Total number of nodes <= 100000
0 < = Nodes values <= 10^9

For Example

Input 1:

       1
      / \
     2   3
    / \  \
   6   4  5
      / \
     12  13 

Output 1:

      4
     / \
    12   13
    Explanation 1:
        cosidering depth of root node as 0.
        maximum depth is 3.
        node with value 12 has depth 3.
        node with value 13 has depth 3.
        smallest subtree which contains 12 and 13 is (4,12,13).
*/ 

TreeNode* dfs(TreeNode* A, int h, int height) {
    if(!A)
        return A;
    if(h == height - 1)
        return A;
    TreeNode* l = dfs(A -> left, h + 1, height);
    TreeNode* r = dfs(A -> right, h + 1, height);
    if(l && r)
        return A;
    if(l)
        return l;     
    return r;
}

int findHeight(TreeNode* A) {
    if(!A)
        return 0;
    return max(findHeight(A -> left), findHeight(A -> right)) + 1;    
}
 
TreeNode* Solution::solve(TreeNode* A) {
    int height = findHeight(A);
    return dfs(A, 0, height);
}

