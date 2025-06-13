class Solution {
    int isvalid(vector<int>& nums, int mid)
    {
        int i=0;
        int count=0;
        while(i<nums.size()-1)
        {
            if(nums[i+1]-nums[i]<=mid)
            {
                count++;
                i++;
            }
            i++;
        }
        return count;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n-1]-nums[0];
        int result=0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(isvalid(nums,mid)>=p)
            {
                result=mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
    return result;
    }
};