class Solution {
    // bool check(vector<int>&nums, int sum, int n)
    // {
    //     if(sum==0)
    //     return true;
    //     if(n<0)
    //     return false;
    //     if(nums[n]>sum)
    //     {
    //         if(check(nums, sum, n-1))
    //         return true;
    //     }
    //     else{
    //         if(check(nums, sum-nums[n], n-1))
    //         return true;
    //         if(check(nums, sum, n-1))
    //         return true;
    //     }
    //     return false;
    // }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int sum1=sum/2+1;
        if(sum%2)
        return false;
        vector<vector<bool>>dp(n,vector<bool>(sum1));
        for(int j=0;j<sum1;j++)
        {
            dp[0][j]=false;
        }
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<sum1;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]= (dp[i-1][j-nums[i-1]] || dp[i-1][j]); 
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][sum/2];
        // if(sum%2)
        // return false;
        // return check(nums, sum/2, n-1);
    }
};