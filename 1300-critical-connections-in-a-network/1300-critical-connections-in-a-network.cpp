class Solution {
    void dfs(int ind, int parent, vector<int>& vis, vector<int>& t,
             vector<int>& low, vector<vector<int>>& ans, int& timer,
             unordered_map<int, list<int>>&adj) {
        vis[ind] = 1;
        t[ind] = low[ind] = timer;
        timer++;

        for (auto it : adj[ind]) {
            if (it == parent)
                continue;
            else if (vis[it] == 0) {
                dfs(it, ind, vis, t, low, ans, timer, adj);
                low[ind] = min(low[ind], low[it]);
                if (low[it] > t[ind]) {
                    ans.push_back({ind, it});
                }
            } else {
                low[ind] = min(low[ind], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        // vector<vector<int>> adj(n);
        // for (auto it : connections) {
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        unordered_map<int, list<int>> adj;
        for (auto i : connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>>ans;
        vector<int> vis(n,0);
        vector<int> t(n);
        vector<int> low(n);
        int timer = 0;
        dfs(0, 0, vis, t, low, ans, timer, adj);
        return ans;
    }
};