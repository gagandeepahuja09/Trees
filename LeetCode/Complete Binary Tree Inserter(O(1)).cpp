class CBTInserter {
public:
    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size(); i++) {
            if(tree[i] -> left)
                tree.push_back(tree[i] -> left);
            if(tree[i] -> right)
                tree.push_back(tree[i] -> right);
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        int n = tree.size();
        int p = (n - 1) / 2;
        if(n % 2)
            tree[p] -> left = node;
        else
            tree[p] -> right = node;
        tree.push_back(node);
        return tree[p] -> val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
