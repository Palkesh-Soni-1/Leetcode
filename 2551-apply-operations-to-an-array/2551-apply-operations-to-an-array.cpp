class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==0)
            count++;
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        if(nums[n-1]==0)
        count++;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            ans.push_back(nums[i]);
        }
        for(int i=0;i<count;i++)
        ans.push_back(0);
        return ans;
    }
};