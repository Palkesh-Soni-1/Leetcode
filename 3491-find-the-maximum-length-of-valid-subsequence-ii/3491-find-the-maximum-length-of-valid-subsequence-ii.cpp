short dp[1000];
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
         short ans=0;
        for (int i=0; i<k; i++){
            fill(dp, dp+k, 0);
            for (int x : nums){
                int j=x%k;
                dp[j]=max(dp[j], short(dp[(i+k-j)%k]+1));
                ans=max(ans, dp[j]);
            }
        }
        return ans;
    }
};