class Solution {
    int kadane(vector<int>&nums)
    {
        int sum=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(sum<=0)
            {
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
public:
    int maxSubArray(vector<int>& nums) {
        return kadane(nums);
    }
};