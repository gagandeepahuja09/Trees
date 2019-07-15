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
    map<pair<TreeNode*, bool>, int> mp;
    int houseRob(TreeNode* root, bool take) {
        if(!root) 
            return 0;
        int ans = 0;
        if(mp.find({ root, take }) != mp.end())
            return mp[{ root, take }];
        if(take) {
            ans = max(ans, root -> val + houseRob(root -> left, false) + houseRob(root -> right, false));
            ans = max(ans, houseRob(root -> left, true) + houseRob(root -> right, true));
        }
        else { 
            ans = max(ans, houseRob(root -> left, true) + houseRob(root -> right, true));
        }
        return mp[{ root, take }] = ans;
    }
    
    int rob(TreeNode* root) {
        return max(houseRob(root, true), houseRob(root, false));
    }
};
