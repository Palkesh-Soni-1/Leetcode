class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            k--;
            if(k<0)
            {
                if(nums[l]==0)
                {
                    k++;
                }
                l++;
            }
        }
        return n-l;
    }
};