class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int min_element1 = *min_element(nums.begin(), nums.end());
        if(k<min_element1)
        {
            unordered_map<int,int>mp;
            for(int i=0;i<nums.size();i++)
            {
                mp[nums[i]]++;
            }
            return (mp.size());
        }
        else if(k==min_element1)
        {
            unordered_map<int,int>mp;
            for(int i=0;i<nums.size();i++)
            {
                mp[nums[i]]++;
            }
            return (mp.size()-1);
        }
        else{
            return -1;
        }
    }
};