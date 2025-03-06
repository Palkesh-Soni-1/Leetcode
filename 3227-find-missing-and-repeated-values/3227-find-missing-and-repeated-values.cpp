class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n = grid.size();
        int a,b;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                mp[grid[i][j]]++;
            }
        }
        for(int i=0;i<(n*n);i++)
        {
            if(mp[i+1]==2)
            a=i+1;
            if(mp[i+1]==0)
            b=i+1;
        }
        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};