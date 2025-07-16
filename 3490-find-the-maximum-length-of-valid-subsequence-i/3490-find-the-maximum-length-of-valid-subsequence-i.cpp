class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ans=0;
        int temp=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2)
            {
                temp++;
            }
        }
        ans=max(ans,temp);
        temp=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                temp++;
            }
        }
        ans=max(ans,temp);
        temp=0;
        int ind=0;
        for(int i=0;i<n;i++)
        {
            if(ind%2==0&&nums[i]%2)
            {
                temp++;
                ind++;
            }
            else if(ind%2&&nums[i]%2==0)
            {
                temp++;
                ind++;
            }
        }
        ans=max(ans,temp);
        temp=0;
        ind=0;
        for(int i=0;i<n;i++)
        {
            if(ind%2==0&&nums[i]%2==0)
            {
                temp++;
                ind++;
            }
            else if(ind%2&&nums[i]%2)
            {
                temp++;
                ind++;
            }
        }
        ans=max(ans,temp);
        return ans;
    }
};