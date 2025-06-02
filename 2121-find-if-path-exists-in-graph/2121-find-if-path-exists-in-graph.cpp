class Solution {
    private:
    void dfs(int src, vector<vector<int>>adj, vector<int>&vis, int destination)
    {
        vis[src]=1;
        if(src==destination)
        return;
        for(auto i: adj[src])
        {
            if(vis[i]==0)
            dfs(i, adj, vis, destination);
        }
    }

    void bfs(int src, vector<vector<int>>adj, vector<int>&vis, int destination)
    {
        vis[src]=1;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
           int x = q.front();
           q.pop();
           for(auto i: adj[x])
           {
            if(vis[i]==0)
            {
                vis[i]=1;
                if(i==destination)
                return;
                q.push(i);
            }
           }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // dfs(source, adj, vis,destination);
        bfs(source, adj, vis, destination);

        if(vis[destination])
        return true;
        return false;
    }
};