void leftView(Node *root) 
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            Node* t = q.front();
            q.pop();
            if(i == 0)
                cout << t -> data << " ";
            if(t -> left)    
                q.push(t -> left);
            if(t -> right)
                q.push(t -> right);
        }
    }
}
