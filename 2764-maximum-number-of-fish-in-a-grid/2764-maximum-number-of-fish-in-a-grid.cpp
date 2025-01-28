class Solution {
    int bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m,int& ans)
    {
        vis[i][j]=1;
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            if(i+row[k]>=0&&i+row[k]<m&&j+col[k]>=0&&j+col[k]<n)
            {
                if(vis[i+row[k]][j+col[k]]==0&&grid[i+row[k]][j+col[k]]!=0)
                {
                    ans+=grid[i+row[k]][j+col[k]];
                    bfs(i+row[k],j+col[k],grid,vis,n,m,ans);
                }
            }
        }
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0&&vis[i][j]==0)
                {
                    int ans1=grid[i][j];
                    ans=max(ans,bfs(i,j,grid,vis,n,m,ans1));
                }
            }
        }
        return ans;
    }
};