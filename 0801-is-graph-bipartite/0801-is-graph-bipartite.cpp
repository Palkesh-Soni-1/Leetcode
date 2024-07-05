class Solution {
    bool check(int start,vector<vector<int>>& graph, vector<int>&v )
    {
        v[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty())
        {
            auto p = q.front();
            start = p;
            q.pop();
            for(auto i:graph[p])
            {
                if(v[i]==-1)
                {
                    v[i]=!v[start];
                    q.push(i);
                    // cout<<v[start]<<" "<<v[i]<<" ";
                }
                else
                {
                    if(v[i]==v[start])
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int>v(n,-1);
        // vector<int>c(n,-1)
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1)
            {
                if(!check(i,graph,v))
                return false;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<" ";
        }
        return true;
    }
};