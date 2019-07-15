/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> st;
    vector<int> ret;
    
    void assignParent(TreeNode* root) {
        if(!root)
            return;
        if(root -> left) {
            parent[root -> left] = root;
        }
        if(root -> right) {
            parent[root -> right] = root;
        }
        assignParent(root -> left);
        assignParent(root -> right);
    }
    
    void findNodes(TreeNode* root, int K) {
        if(!root || st.find(root) != st.end())
            return;
        if(K == 0) {
            ret.push_back(root -> val);
        }
        st.insert(root);
        findNodes(root -> left, K - 1);
        findNodes(root -> right, K - 1);
        findNodes(parent[root], K - 1);   
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        assignParent(root);
        findNodes(target, K);
        
        return ret;
    }
};
