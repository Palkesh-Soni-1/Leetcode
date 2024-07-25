class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while(low<=high)
        {
            int m = low+(high-low)/2;
            if(nums[m]==target)
            return m;
            if(nums[m]>target)
            high = m-1;
            else
            low = m+1;
        }
        return -1;
    }
};