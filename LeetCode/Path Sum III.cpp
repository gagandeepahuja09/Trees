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
    unordered_map<int, int> preSum;
    int count = 0, currSum = 0;
    
    void dfs(TreeNode* root, int sum) {
        if(!root)
            return;
        currSum += (root -> val);
        if(preSum.find(currSum - sum) != preSum.end())
            count += preSum[currSum - sum];
        preSum[currSum]++;
        dfs(root -> left, sum);
        dfs(root -> right, sum);
        preSum[currSum]--;
        currSum -= (root -> val);
    }
    
    int pathSum(TreeNode* root, int sum) {
        preSum.clear();
        preSum[0] = 1;
        count = currSum = 0;
        dfs(root, sum);
        return count;
    }
};
