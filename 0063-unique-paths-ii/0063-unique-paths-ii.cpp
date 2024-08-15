class Solution {
    int solve(int m, int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid)
    {
        if(m==0&&n==0)
        {
            return 1;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int u=0,l=0;
        if(m-1>=0)
        {
            if(obstacleGrid[m-1][n]==1);
            else
            u = solve(m-1,n,dp,obstacleGrid);  
        }
        if(n-1>=0)
        {
            if(obstacleGrid[m][n-1]==1);
            else
            l = solve(m,n-1,dp,obstacleGrid);
        }
        return dp[m][n]=l+u;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[m-1][n-1]==1)
        return 0;
        return solve(m-1,n-1,dp,obstacleGrid);
    }
};