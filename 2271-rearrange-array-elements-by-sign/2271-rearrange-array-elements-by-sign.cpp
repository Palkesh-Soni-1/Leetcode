class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
    vector<int>pos;
    vector<int>neg;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            neg.push_back(nums[i]);
        }
        else{
            pos.push_back(nums[i]);
        }
    }
    int x = n/2;
    for(int i=0;i<x;i++)
    {
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }
    return ans;
    }
};