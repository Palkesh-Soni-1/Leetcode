class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        int le = flights.size();
        for(int i=0;i<le;i++)
        {
            int a = flights[i][0];
            int b = flights[i][1];
            int c = flights[i][2];
            adj[a].push_back({b,c});
        }
        vector<int>dis(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int stops = p.first;
            int des = p.second.first;
            int dist = p.second.second;
            if(stops>k)
            continue;
            for(auto i:adj[des])
            {
                if(dist+i.second<dis[i.first])
                {
                    dis[i.first]=dist+i.second;
                    q.push({stops+1,{i.first,dist+i.second}});
                }
            }
        }
        if(dis[dst]==1e9)
        return -1;
        return dis[dst];
    }
};