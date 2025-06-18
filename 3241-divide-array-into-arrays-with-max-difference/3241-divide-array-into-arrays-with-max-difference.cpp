class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        // int flag=0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int x=0;
        while(x<n)
        {
            if((nums[x+2]-nums[x])>k)
            {
                return {};
            }
            vector<int>temp;
            for(int i=x;i<x+3;i++)
            {
                temp.push_back(nums[i]);
            }
            ans.push_back(temp);
            x+=3;
        }
        return ans;
    }
};