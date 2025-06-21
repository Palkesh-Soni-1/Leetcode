class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix;
        vector<int>suffix;
        prefix.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            prefix.push_back(prefix.back()+nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            suffix.push_back(sum-nums[i]-prefix[i]);
        }
        cout<<prefix.size()<<" "<<suffix.size()<<endl;
        for(int i=0;i<prefix.size()-1;i++)
        {
            // cout<<prefix[i]<<" "<<endl;
            // cout<<suffix[i]<<" "<<endl;
            if(suffix[i]==prefix[i])
            return i;
        }
        return -1;
    }
};