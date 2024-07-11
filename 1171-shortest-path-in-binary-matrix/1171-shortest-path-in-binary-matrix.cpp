class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        int row[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int col[] = {0, 0, 1, -1, -1, 1, -1, 1};
        dis[0][0] = 0;
        if (grid[0][0] == 0) {

            q.push({0, {0, 0}});
        }
        while (!q.empty()) {
            auto p = q.front();
            int di = p.first;
            int ro = p.second.first;
            int co = p.second.second;
            q.pop();
            cout << "run1" << endl;
            for (int i = 0; i < 8; i++) {
                int nr = ro + row[i];
                int nc = co + col[i];
                if (nc >= 0 && nc < n && nr >= 0 && nr < n &&
                    grid[nr][nc] == 0) {
                    if (di + 1 < dis[nr][nc]) {
                        dis[nr][nc] = di + 1;
                        q.push({di + 1, {nr, nc}});
                        if (nr == n - 1 && nc == n - 1) {
                            return di + 1 + 1;
                        }
                    }
                }
            }
            if (ro == n - 1 && co == n - 1) {
                return di + 1;
            }
        }
        return -1;
    }
};