/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    vector<TreeNode*> roots;
    TreeNode* head;
    int i = -1;
    
public:
    void pre(TreeNode* root, vector<TreeNode*>& roots) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* t =  q.front();
            q.pop();
            roots.push_back(t);
            if(t -> left)
                q.push(t -> left);
            if(t -> right)
                q.push(t -> right);
            if(t -> left && t -> right)
                i++;
        }
    }
    
    CBTInserter(TreeNode* root) {
        roots.clear();
        head = root;
        pre(root, roots);
        i++;
    }
    
    int insert(int v) {
        TreeNode* node = roots[i];
        TreeNode* child = new TreeNode(v);
        if(node -> left == NULL) {
            node -> left = child;
        }
        else
            node -> right = child;
        if(node -> left && node -> right)
            i++;
        roots.push_back(child);
        return node -> val;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
