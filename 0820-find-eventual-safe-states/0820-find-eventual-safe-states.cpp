class Solution {
    private:
    bool dfs(int start,vector<int>&vis,vector<vector<int>>&graph,vector<int>&ans,vector<int>&path,vector<int>&check)
    {
        vis[start]=1;
        path[start]=1;
        int n = graph[start].size();
        int count=0;
        for(int i=0;i<n;i++)
        {

            if(vis[graph[start][i]]==0)
            {
                if(dfs(graph[start][i],vis,graph,ans,path,check)) 
                count++;
            }
            else{
                if(path[graph[start][i]])
                return false;
                else if(check[graph[start][i]])
                count++;
            }
        }
        path[start]=0;
        if(count==n)
        {
            check[start]=1;
            ans.push_back(start);
            return true;
        }
        else 
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>check(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,graph,ans,path,check);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};