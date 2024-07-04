class Solution {
    private:
    void dfs(int row,int col, vector<vector<int>>&vis, vector<vector<char>>&board, int delrow[], int delcol[], int n, int m)
    {
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,board,delrow, delcol,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int j=0;j<m;j++)
        {
            if(vis[0][j]==0&&board[0][j]=='O')
            {
                dfs(0,j,vis,board,delrow, delcol,n,m);
            }
            if(vis[n-1][j]==0&&board[n-1][j]=='O')
            {
                dfs(n-1,j,vis,board,delrow, delcol,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i][0]==0&&board[i][0]=='O')
            {
                dfs(i,0,vis,board,delrow, delcol,n,m);
            }
            if(vis[i][m-1]==0&&board[i][m-1]=='O')
            {
                dfs(i,m-1,vis,board,delrow, delcol,n,m);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O'&&vis[i][j]==0)
                {
                    board[i][j]='X';
                }
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};