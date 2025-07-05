class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();

        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int ans = -1;
        for(auto i:mp)
        {
            if(i.second==i.first)
            {
                ans = max(ans, i.second);
            }
        }
        return ans;
    }
};