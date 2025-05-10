class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        while(j<nums.size()&&i<nums.size())
        {
            if(nums[j]==nums[i])
            j++;
            else
            {
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};