void printLeft(Node *root) {
    if(!root)
        return;
    if(root -> left || root -> right)
        cout << root -> data << " ";
    if(root -> left)
        printLeft(root -> left);
    else
        printLeft(root -> right);
}

void printRight(Node *root) {
    if(!root)
        return;
    if(root -> right)
        printRight(root -> right);
    else 
        printRight(root -> left);
    if(root -> left || root -> right)    
        cout << root -> data << " ";    
}

void printBottom(Node *root) {
    if(!root)
        return;
    if(!root -> left && !root -> right)
        cout << root -> data << " ";
    printBottom(root -> left);
    printBottom(root -> right);
}

void printBoundary(Node *root) {
    if(root) {
        cout << root -> data << " ";
        printLeft(root -> left);
        printBottom(root);
        printRight(root -> right);
    }
}
