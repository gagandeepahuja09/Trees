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
    bool isCompleteTree(TreeNode* root) {
        int i = 0;
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        while(i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i] -> left);
            bfs.push_back(bfs[i] -> right);
            i++;
        }
        while(i < bfs.size() && !bfs[i])
            i++;
        return (i == bfs.size());
    }
};
