class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        int i=0;
        int j=k;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        // cout<<sum<<" "<<k<<endl;
        double avg = sum/k;
        // cout<<avg<<endl;
        double ans = avg;
        while(j<nums.size())
        {
            sum+=nums[j];
            sum-=nums[i];
            i++;
            j++;
            avg = sum/k;
            // cout<<sum<<" "<<k<<endl;
            // cout<<avg<<endl;
            ans = max(ans,avg);
        }
        ans = round(ans*100000)/100000;
        return ans;
    }
};