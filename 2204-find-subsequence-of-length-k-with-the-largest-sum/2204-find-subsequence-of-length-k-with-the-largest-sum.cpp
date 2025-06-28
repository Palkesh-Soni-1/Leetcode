class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>temp;
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back({nums[i],i});
        }
        sort(temp.rbegin(), temp.rend());
        vector<int>temp2(nums.size(),INT_MIN);
        for(int i=0;i<k;i++)
        {
            temp2[temp[i].second]=(temp[i].first);
        }

        vector<int>ans;

        for(int i=0;i<nums.size();i++)
        {
            if(temp2[i]!=INT_MIN)
            ans.push_back(temp2[i]);
        }
        return ans;
    }
};