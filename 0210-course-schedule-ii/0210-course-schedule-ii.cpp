class Solution {
    private: 
    vector<int> bfs(int numCourses, vector<vector<int>>& prerequisites,int n,  vector<vector<int>>adj){

        //topological sort -> kahn's algorithm => detect cycle in directed graph using bfs
        vector<int>ans;
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
            ans.push_back(x);
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
        reverse(ans.begin(), ans.end());
        if(count>=numCourses)
        return ans;
        return {};
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        return bfs(numCourses, prerequisites, n, adj);
    }
};