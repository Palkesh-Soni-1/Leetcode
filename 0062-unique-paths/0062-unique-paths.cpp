class Solution {
    int solve(int m, int n,vector<vector<int>>&dp)
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
            u = solve(m-1,n,dp);  
        }
        if(n-1>=0)
        {
            l = solve(m,n-1,dp);
        }
        return dp[m][n]=l+u;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};