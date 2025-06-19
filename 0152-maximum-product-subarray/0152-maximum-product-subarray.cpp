class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int prefix = 1;
        int suffix =1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-i-1];
            ans = max(ans, max(prefix,suffix));
            if(nums[i]==0)
            {
                prefix = 1;
            }
            if(nums[n-i-1]==0)
            {
                suffix = 1;
            }
        }
        return ans;
    }
};