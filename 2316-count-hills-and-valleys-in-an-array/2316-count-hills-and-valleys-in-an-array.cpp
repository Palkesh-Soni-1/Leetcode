class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int temp = i-1;
            int left=0, right=0;
            while(temp>=0)
            {
                if(nums[temp]!=nums[i])
                {
                    left = nums[temp];
                    break;
                }
                temp--;
            }
            temp = i+1;
            while(temp<n)
            {
                if(nums[temp]!=nums[i])
                {
                    right = nums[temp];
                    break;
                }
                temp++;
            }
            i=temp-1;
            if(left!=0&&right!=0&&((left<nums[i]&&right<nums[i])||(left>nums[i]&&right>nums[i])))
            ans++;
        }
        return ans;
    }
};