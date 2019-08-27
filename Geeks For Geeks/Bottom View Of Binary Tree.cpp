map<int,int> mp;

void findBottom(Node *root, int dir) {
    if(!root)
        return;
    mp[dir] = root->data;
    findBottom(root -> left, dir - 1);
    findBottom(root -> right, dir + 1);
}

void bottomView(Node *root) {
    mp.clear();
    findBottom(root, 0);
    for(auto it : mp) {
        cout << it.second << " ";
    }
}
