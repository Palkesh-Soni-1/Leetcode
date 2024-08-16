int solve(int i, int w, vector<int> wt, vector<vector<int>>&dp)
{
    if(w==0)
    {
        return 0;
    }
    if(i==0)
    {
        int x = w/wt[i];
        if((w)%wt[i]==0)
        return (1 * x);
        return 1e7;
    }
    if(dp[i][w]!=-1)
    return dp[i][w];
    int take=INT_MAX;
    if(w-wt[i]>=0)
    take = 1 + solve(i,w-wt[i],wt,dp);
    int ntake = 0 + solve(i-1,w,wt,dp);
    return dp[i][w]=min(ntake,take);
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        vector<vector<int>>dp(N,vector<int>(amount+1,-1)) ; 
        int ans = solve(N-1, amount ,coins,dp); 
        if(ans==1e7)
        return -1;
        return ans;
    }
};