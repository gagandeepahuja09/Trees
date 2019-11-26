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
    int ans = 0;
    void dfs(TreeNode* root, int sum, unordered_map<int, int>& prevSums, int currSum) {
        if(!root)
            return;
        currSum += (root -> val);
        if(prevSums.find(currSum - sum) != prevSums.end())
            ans += prevSums[currSum - sum];
        prevSums[currSum]++;
        dfs(root -> left, sum, prevSums, currSum);
        dfs(root -> right, sum, prevSums, currSum);
        prevSums[currSum]--;
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> prevSums;
        prevSums[0] = 1;
        dfs(root, sum, prevSums, 0);
        return ans;
    }
};
