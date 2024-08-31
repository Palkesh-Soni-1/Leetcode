class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix=0, cnt=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            int remove = prefix-k;
            cnt+=mp[remove];
            mp[prefix]++;
        }
        return cnt;
    }
};