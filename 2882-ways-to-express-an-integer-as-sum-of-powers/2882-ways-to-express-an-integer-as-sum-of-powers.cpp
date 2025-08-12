int m = 1e9+7;
class Solution {
    int solve(int n, int num, int x, vector<vector<int>>&dp)
    {
        if(n==0)
        return 1;
        if(n<0||pow(num,x)>n)
        return 0;

        if(dp[n][num]!=-1)
        return dp[n][num];

        int take = solve(n-pow(num,x), num+1, x,dp)%m;
        int ntake = solve(n, num+1, x, dp)%m;

        return dp[n][num]=(take+ntake)%m;
    }

public:
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solve(n,1,x,dp)%m;
    }
};