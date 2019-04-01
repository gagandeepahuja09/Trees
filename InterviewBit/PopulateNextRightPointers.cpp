/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
TreeLinkNode* getNext(TreeLinkNode* root) {
    TreeLinkNode* temp = root -> next;
    while(temp) {
        if(temp -> left)
            return temp -> left;
        if(temp -> right)
            return temp -> right;
        temp = temp -> next;    
    }
    return NULL;
} 
 
void Solution::connect(TreeLinkNode* A) {
    if(!A)
        return;
    A -> next = NULL;
    while(A) {
        // Connect all children nodes of A and all other children
        // Node at same level as A
        TreeLinkNode* B = A;
        while(B) {
            if(B -> left) {
                if(B -> right)
                    B -> left -> next = B -> right;
                else
                    B -> left -> next = getNext(B);
            }
            if(B -> right)
                B -> right -> next = getNext(B);
            B = B -> next;    
        }
        if(A -> left)
            A = A -> left;
        else if(A -> right)
            A = A -> right;
        else
            A = getNext(A);
    }
}


