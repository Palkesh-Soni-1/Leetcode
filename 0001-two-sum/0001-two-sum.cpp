class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,pair<int,int>>mp;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]={1,i};
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                if(i!=mp[target-nums[i]].second)
                {
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]].second);
                break;
                }
            }
        }
        return ans;
    }
};