class Solution {
public:
    int findLHS(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0,j=0;
        int ans=0;
        int temp=0;
        while(i<n&&j<n)
        {
            if(nums[j]-nums[i]<=0)
            {
                j++;
            }
            else if(nums[j]-nums[i]==1)
            {
                temp=j-i+1;
                j++;
            }
            else{
                i++;
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};