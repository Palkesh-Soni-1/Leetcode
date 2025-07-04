class Solution {

    vector<int>dp;

    int solve(int n, vector<int>&cost)
    {
        if(n==0||n==1)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        return dp[n]=min(cost[n-1]+solve(n-1,cost), cost[n-2]+solve(n-2,cost));
    }


public:
    int minCostClimbingStairs(vector<int>& cost) {
        dp = vector<int>(cost.size()+1,-1);
        return solve(cost.size(), cost);
    }
};