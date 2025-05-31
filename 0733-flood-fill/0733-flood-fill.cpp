class Solution {
    private:
    void dfs(int sr,int sc,int imp, int color,vector<vector<int>>&temp,vector<vector<int>>& image,int n,int m)
    {
        // int n = temp.size();
        // int m = temp[0].size();
        temp[sr][sc]=color;

        int d[] = {-1,0,1,0};
        int f[] = {0,-1,0,1};

        for(int i=0;i<4;i++)
        {
            if(sr+d[i]>=0&&sr+d[i]<n&&sc+f[i]>=0&&sc+f[i]<m&&image[sr+d[i]][sc+f[i]]==imp&&temp[sr+d[i]][sc+f[i]]!=color)
            dfs(sr+d[i],sc+f[i],imp,color,temp,image,n,m);
        }
        // if((sr-1)>=0&&image[sr-1][sc]==imp&&temp[sr-1][sc]!=color)
        // {
        //     dfs(sr-1,sc,imp,color,temp,image,n,m);
        // }
        // if((sr+1)<n&&(image[sr+1][sc]==imp)&&temp[sr+1][sc]!=color)
        // {
        //     // cout<<"run"<<endl;
        //     // cout<<sr<<" "<<sc<<endl;
        //     dfs(sr+1,sc,imp,color,temp,image,n,m);`
        // }
        // if(sc-1>=0&&image[sr][sc-1]==imp&&temp[sr][sc-1]!=color)
        // {
        //     dfs(sr,sc-1,imp,color,temp,image,n,m);
        // }
        // if(sc+1<m&&image[sr][sc+1]==imp&&temp[sr][sc+1]!=color)
        // {
        //     dfs(sr,sc+1,imp,color,temp,image,n,m);
        // }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>temp = image;
        int colo = color;
        int n = temp.size();
        int m = temp[0].size();
        int imp = temp[sr][sc];
        dfs(sr,sc,imp,colo,temp,image,n,m);
        return temp;
    }
};