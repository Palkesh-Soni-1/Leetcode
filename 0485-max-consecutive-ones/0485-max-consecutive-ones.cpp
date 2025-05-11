class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0;
        int mlen=0;
        while(j<nums.size())
        {
            if(nums[j]==1){
                j++;
            }
            else{
                int len = j-i;
                mlen = max(mlen, len);
                i = j;
                i++;
                j++;
            }
        }
        int len = j-i;
        mlen = max(mlen, len);
        return mlen;
    }
};