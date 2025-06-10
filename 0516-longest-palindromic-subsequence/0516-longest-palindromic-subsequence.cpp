class Solution {
int solve(string s, long int i, long int j, vector<vector<int>>&dp)
{
    if(i>j)
    return 0;
    if(i==j)
    {
        if(s[i]==s[j])
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=0;
    int ans1=0;
    if(s[i]==s[j])
    {
        ans = 2 + solve(s,i+1,j-1,dp);
    }
    else{
        ans1 = max(solve(s,i+1,j,dp), solve(s,i,j-1,dp));
    }
    return dp[i][j]=max(ans,ans1);

}
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return solve(s,0,n-1,dp);
        //tabulation
        // int ans=0;
        //method 2 take t as reverse of s the find LCS
        string t=s; 
        reverse(t.begin(), t.end());
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};