class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> xorSubtree(n, 0);
        vector<int> parent(n, -1);
        vector<int> entry(n, 0), exit(n, 0);
        int time = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            entry[u] = time++;
            xorSubtree[u] = nums[u];
            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u);
                    xorSubtree[u] ^= xorSubtree[v];
                }
            }
            exit[u] = time++;
        };

        dfs(0, -1);

        int totalXOR = xorSubtree[0];
        int minScore = INT_MAX;

        for (int i = 0; i < edges.size(); ++i) {
            int a1 = edges[i][0], b1 = edges[i][1];
            if (parent[a1] == b1) swap(a1, b1);
            for (int j = i + 1; j < edges.size(); ++j) {
                int a2 = edges[j][0], b2 = edges[j][1];
                if (parent[a2] == b2) swap(a2, b2);

                int x, y, z;
                if (entry[b1] <= entry[b2] && exit[b2] <= exit[b1]) {
                    x = xorSubtree[b2];
                    y = xorSubtree[b1] ^ xorSubtree[b2];
                    z = totalXOR ^ xorSubtree[b1];
                } else if (entry[b2] <= entry[b1] && exit[b1] <= exit[b2]) {
                    x = xorSubtree[b1];
                    y = xorSubtree[b2] ^ xorSubtree[b1];
                    z = totalXOR ^ xorSubtree[b2];
                } else {
                    x = xorSubtree[b1];
                    y = xorSubtree[b2];
                    z = totalXOR ^ x ^ y;
                }

                int currentMax = max({x, y, z});
                int currentMin = min({x, y, z});
                minScore = min(minScore, currentMax - currentMin);
            }
        }

        return minScore;
    }
};