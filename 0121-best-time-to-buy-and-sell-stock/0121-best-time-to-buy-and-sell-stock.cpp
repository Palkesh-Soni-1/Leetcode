class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>temp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            temp[i]=max(prices[i],temp[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, temp[i]-prices[i]);
        }
        return ans;
    }
};