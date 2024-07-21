class Solution {
    int calculate(int ind, vector<int>&nums, int &sum, vector<int>&dp)
    {
        if(ind>=nums.size())
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        //take
        sum = sum+nums[ind];
        int sum1 = nums[ind]+calculate(ind+2,nums,sum,dp);
        //not take
        sum = sum-nums[ind];
        int sum2 = calculate(ind+1,nums,sum,dp);
        sum = max(sum1,sum2);
        dp[ind]=sum;
        return sum;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        int sum=0;
        vector<int>dp(n,-1);
        int ans = calculate(0,nums,sum,dp);
        return ans;
    }
};