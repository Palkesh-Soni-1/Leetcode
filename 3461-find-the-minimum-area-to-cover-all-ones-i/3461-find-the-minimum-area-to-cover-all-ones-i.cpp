class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r=-1;
        int c = -1;
        int r1=INT_MAX;
        int c1 = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    r = max(r,i);
                    c = max(c,j);
                    r1 = min(r1,i);
                    c1 = min(c1,j);
                    flag = 1;
                }
            }
        }
        r = r - r1;
        c = c - c1;
        if(r==0&&c==0&&flag)
        return 1;
        return (r+1)*(c+1);
    }
};