class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int a = p.first.first;
            int b = p.first.second;
            int c = p.second;
            if(a+1<n&&vis[a+1][b]!=1)
            {
                vis[a+1][b]=1;
                ans[a+1][b]=c+1;
                q.push({{a+1,b},c+1});
            }
            if(b+1<m&&vis[a][b+1]!=1)
            {
                vis[a][b+1]=1;
                ans[a][b+1]=c+1;
                q.push({{a,b+1},c+1});
            }
            if(a-1>=0&&vis[a-1][b]!=1)
            {
                vis[a-1][b]=1;
                ans[a-1][b]=c+1;
                q.push({{a-1,b},c+1});
            }
            if(b-1>=0&&vis[a][b-1]!=1)
            {
                vis[a][b-1]=1;
                ans[a][b-1]=c+1;
                q.push({{a,b-1},c+1});
            }
        }
        return ans;
    }
};