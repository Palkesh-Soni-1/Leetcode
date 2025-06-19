class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int cnt=0;
        int product1=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            cnt++;
            else
            product1*=nums[i];
        }
        if(cnt>1)
        {
            return ans;
        }
        else if(cnt==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                ans[i]=product1;
            }
            return ans;
        }
        else{
            for(int i=0;i<n;i++)
            {
                ans[i]=product1/nums[i];
            }
            return ans;
        }
    }
};