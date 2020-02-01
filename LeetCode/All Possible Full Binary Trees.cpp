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
    unordered_map<int, vector<TreeNode*>> cache;
    vector<TreeNode*> ret;
    vector<TreeNode*> f(int N) {
        vector<TreeNode*> ret;
        if(cache[N].size())
            return cache[N];
        if(N == 1) {
            ret.push_back(new TreeNode(0));
            return cache[N] = ret;
        }
        for(int i = 1; i < N; i += 2) {
            vector<TreeNode*> lAns = f(i);
            vector<TreeNode*> rAns = f(N - i - 1);
            for(TreeNode* left : lAns) {
                for(TreeNode* right : rAns) {
                    TreeNode* root = new TreeNode(0);
                    root -> left = left;
                    root -> right = right;
                    ret.push_back(root);
                }
            }
        }
        return cache[N] = ret;
    }
    
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0)
            return vector<TreeNode*>({});
        return f(N);
    }
};
