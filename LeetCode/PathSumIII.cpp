class Solution {
public:
    int sum(TreeNode* root, int curr, int target, unordered_map<int, int>& mp) {
        if(!root)
            return 0;
        curr += root -> val;
        int ans = mp[curr - target];
        mp[curr]++;
        ans += sum(root -> left, curr, target, mp) 
            + sum(root -> right, curr, target, mp);
        mp[curr]--;
        return ans;
    }
    
    int pathSum(TreeNode* root, int s) {
        if(!root)
            return 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
         return sum(root, 0, s, mp);
    }
};
