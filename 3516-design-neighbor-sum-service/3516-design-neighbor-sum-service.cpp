class neighborSum {
    int n;
    vector<vector<int>>v;
public:
    neighborSum(vector<vector<int>>& grid) {
        int x = grid.size();
        n = x;
        v = grid;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         v[i][j]=grid[i][j];
        //     }
        // }
    }
    
    int adjacentSum(int value) {
        int ans=0;
        int r,c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==value)
                {
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        if(r-1>=0)
        ans = ans+v[r-1][c];
        if(r+1<n)
        ans = ans+v[r+1][c];
        if(c-1>=0)
        ans = ans+v[r][c-1];
        if(c+1<n)
        ans = ans+v[r][c+1];
        return ans;
    }
    
    int diagonalSum(int value) {
        int ans=0;
        int r,c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==value)
                {
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        if(r-1>=0&&c-1>=0)
        ans = ans+v[r-1][c-1];
        if(r+1<n&&c-1>=0)
        ans = ans+v[r+1][c-1];
        if(r+1<n&&c+1<n)
        ans = ans+v[r+1][c+1];
        if(r-1>=0&&c+1<n)
        ans = ans+v[r-1][c+1];
        return ans;
    }
};

