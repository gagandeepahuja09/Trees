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
    TreeNode* recoverTree(string s, int& i, int l) {
        if(i == s.size())
            return NULL;
        int cnt = 0;
        while(i < s.size() && s[i] == '-') {
            cnt++;
            i++;
        }
        if(cnt < l) {
            i -= cnt;
            return NULL;
        }
        int num = 0;
        while(i < s.size() && s[i] != '-') {
            num = num * 10 + (s[i++] - '0');
        }
        
        TreeNode* root = new TreeNode(num);
        root -> left = recoverTree(s, i, l + 1);
        root -> right = recoverTree(s, i, l + 1);
        return root;
    }
    
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        return recoverTree(S, i, 0);
    }
};
