class Solution {
private:
    bool dfs(int start, vector<vector<int>>adj, vector<int>&vis, vector<int>&path)
    {

        //===tle
        vis[start]=1;
        path[start]=1;
        for(auto i: adj[start])
        {
            if(vis[i]==0)
            {
                if(dfs(i, adj, vis, path)==false)
                return false;
            }
            else if(path[i]==1)
            return false;
            else{
                if(dfs(i, adj, vis, path)==false)
                return false;
            }
        }
        path[start]=0;
        return true;
    }

    bool bfs(int numCourses, vector<vector<int>>& prerequisites,int n,  vector<vector<int>>adj){
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            indegree[prerequisites[i][1]]++;
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                count++;
            }
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i:adj[x])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    count++;
                    q.push(i);
                }
            }
        }
        if(count>=numCourses)
        return true;
        return false;




        //======wrong approach
        // queue<int>q;
        // q.push(start);
        // vis[start]=1;
        // while(!q.empty())
        // {
        //     auto x = q.front();
        //     q.pop();
        //     for(auto i: adj[x])
        //     {
        //         if(vis[i]==1)
        //         return false;
        //         else{
        //             vis[i]=1;
        //             q.push(i);
        //         }
        //     }
        // }
        // return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>vis(numCourses,0);
        vector<int>path(numCourses,0);
        // for(int i=0;i<numCourses;i++)
        // {
        //     if(vis[i]==0)
        //     {
        //         // if(dfs(i, adj, vis, path)==false)
        //         // return false;
        //     }
        // }
        // return true;
        return bfs(numCourses, prerequisites, n, adj);
    }
};