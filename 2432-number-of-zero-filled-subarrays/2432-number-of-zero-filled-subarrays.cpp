class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int length=0;
        long long ans=0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            length++;
            else
            length=0;
            ans+=length;
        }
        return ans;
    }
};