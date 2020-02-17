class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> ret;
    vector<int> count;
    int ans = 0;
    
    void dfs(int root, int prev) {
        for(auto i : tree[root]) {
            if(i == prev)
                continue;
            dfs(i, root);
            count[root] += count[i];
            ret[root] += count[i] + ret[i]; 
        }
    }
    
    void dfs2(int root, int prev) {
        for(auto i : tree[root]) {
            if(i == prev)
                continue;
            ret[i] = ret[root] - count[i] + count.size() - count[i]; 
            dfs2(i, root);
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        ret.assign(N, 0);
        count.assign(N, 1);
        for(auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ret;
    }
};
