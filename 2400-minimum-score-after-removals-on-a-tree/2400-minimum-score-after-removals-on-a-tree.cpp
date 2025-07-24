class Solution {
private:
    vector<vector<int>> adj;
    vector<int> nums;
    vector<int> xorSubtree;
    vector<int> parent;
    vector<int> entry;
    vector<int> exit;
    int timer;

    void dfs(int u, int p) {
        parent[u] = p;
        entry[u] = timer++;
        xorSubtree[u] = nums[u];
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
                xorSubtree[u] ^= xorSubtree[v];
            }
        }
        exit[u] = timer++;
    }

    bool isInSubtree(int parentNode, int childNode) {
        return entry[parentNode] <= entry[childNode] && exit[childNode] <= exit[parentNode];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        int n = nums.size();
        adj.resize(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        xorSubtree.resize(n);
        parent.resize(n, -1);
        entry.resize(n);
        exit.resize(n);
        timer = 0;
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
                if (isInSubtree(b1, b2)) {
                    x = xorSubtree[b2];
                    y = xorSubtree[b1] ^ xorSubtree[b2];
                    z = totalXOR ^ xorSubtree[b1];
                } else if (isInSubtree(b2, b1)) {
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