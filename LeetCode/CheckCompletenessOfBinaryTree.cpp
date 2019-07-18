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
    bool isComplete(TreeNode* root, int i, int count) {
        if(!root) {
            return true;
        }
        if(i > count)
            return false;
        return isComplete(root -> left, 2 * i, count) && isComplete(root -> right, 2 * i + 1, count);
    }
    
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    bool isCompleteTree(TreeNode* root) {
        // int cnt = countNodes(root);
        // return isComplete(root, 1, cnt);
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        while(i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i] -> left);
            bfs.push_back(bfs[i] -> right);
            i++;
        }
        while(i < bfs.size() && !bfs[i]) {
            i++;
        }
        return (i >= bfs.size());
    }
};
