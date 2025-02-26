class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        //modified kadane theorem

        int sum=0, minsum=0, maxsum=0;
        for(auto i:nums)
        {
            sum+=i;
            if(sum>maxsum)
            maxsum=sum;
            if(sum<minsum)
            minsum=sum;
        }
        int ans=maxsum-minsum;
        return ans;
        // vector<int>presum;
        // int sum=0;
        // for(auto i:nums)
        // {
        //     sum+=i;
        //     presum.push_back(abs(i)l);
        // }
        // return ans;
    }
};