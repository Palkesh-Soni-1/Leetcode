class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int k = 0;
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (grid[i][k] == grid[k][j]) {
                        cnt++;
                    }
                    else
                    break;
                }
                if(cnt==n)
                ans++;
            }
        }
        return ans;
    }
};