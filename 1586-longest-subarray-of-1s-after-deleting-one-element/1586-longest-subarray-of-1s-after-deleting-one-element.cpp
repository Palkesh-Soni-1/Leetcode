class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int n = nums.size();
        int k=1;
        for(int r=0;r<n;r++)
        {
            if(nums[r]==0)
            k--;
            if(k<0)
            {
                if(nums[l]==0)
                k++;
                l++;
            }
        }
        return n-l-1;
    }
};