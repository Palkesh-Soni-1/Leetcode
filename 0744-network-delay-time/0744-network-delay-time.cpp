class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj(n, vector<int>(n,1000));
        int items = times.size();
        for(int i=0;i<items;i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u-1][v-1]=w;
        }
        for(int i=0;i<n;i++)
        {
            adj[i][i]=0;
        }

        int ans=0;
        for(int via=0; via<n; via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                adj[i][j] = min(adj[i][j], adj[i][via]+adj[via][j]);
            }
        }

        for(int i=0;i<n;i++)
        {
            ans = max(ans, adj[k-1][i]);
        }
        if(ans==1000)
        return -1;
        return ans;
    }
};