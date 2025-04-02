class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long int maxi=0;
        for(int i=0;i<=n-3;i++)
        {
            for(int j=i+1;j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    long long a = (nums[i]-nums[j]);
                    long long ans = a*nums[k];
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }
};