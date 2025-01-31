// class Solution {
//     void dfs(vector<vector<int>>& grid, int &count, int i, int j, vector<vector<int>>& vis, int n, int m)
//     {
//         vis[i][j]=1;
//         int a[4]={-1,0,1,0};
//         int b[4]={0,1,0,-1};
//         for(int k=0;k<4;k++)
//         {
//             int row = a[k]+i;
//             int col = b[k]+j;
//             if(row<n&&row>=0&&col<m&&col>=0&&grid[row][col]==1&&vis[i][j]==0)
//             {
//                 cout<<"count"<<endl;
//                 count++;
//                 dfs(grid, count, row, col, vis, n, m);
//             }
//         }
//     }
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 int count=0;
//                 vector<vector<int>>vis(n, vector<int>(m,0));
//                 if(grid[i][j]==1)
//                 {
//                     count++;
//                     dfs(grid, count, i, j, vis, n, m);
//                 }
//                 else{
//                     grid[i][j]=1;
//                     count++;
//                     dfs(grid, count, i, j, vis, n, m);
//                     grid[i][j]=0;
//                 }
//                 ans=max(ans,count);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
private:
    int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow,
                      int currentColumn) {
        if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
            currentColumn >= grid[0].size() ||
            grid[currentRow][currentColumn] != 1)
            return 0;

        grid[currentRow][currentColumn] = islandId;
        return 1 +
               exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSizes;
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 1) {
                    islandSizes[islandId] = exploreIsland(
                        grid, islandId, currentRow, currentColumn);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty()) {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1) {
            --islandId;
            return (islandSizes[islandId] == grid.size() * grid[0].size())
                       ? islandSizes[islandId]
                       : islandSizes[islandId] + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting
        // island size
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};