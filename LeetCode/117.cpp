/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* fnext(Node* root) {
        if (!root)
            return NULL;
        if (root -> left)
            return root -> left;
        if (root -> right)
            return root -> right;
        return fnext(root -> next);
    }
    
    void connectV2(Node* root) {
        if (!root) {
            return;
        }
        if (root -> left) {
            if (root -> right) {
                root -> left -> next = root -> right;
            } else {
                root -> left -> next = fnext(root -> next);
            }
        }
        if (root -> right) {
            root -> right -> next = fnext(root -> next);
        }
        connectV2(root -> right);
        connectV2(root -> left);
    }
    
    Node* connect(Node* root) {
        connectV2(root);
        return root;
    }
};
