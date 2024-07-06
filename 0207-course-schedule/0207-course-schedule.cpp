class Solution {
    private:
    bool cycle(int start, vector<int>&vis,vector<vector<int>>&dum, vector<int>&ans, vector<int>&path)
    {
        vis[start]=1;
        path[start]=1;
        for(auto i:dum[start])
        {
            if(vis[i]==0)
            {
                if(cycle(i,vis,dum,ans,path)==false)
                {
                 return false;
                }
            }
            else if(path[i]==1)
            {
                path[i]=0;
                return false;
            }
        }
        path[start]=0;
        return true;
    }
    void dfs(int start,vector<int>&visi,vector<vector<int>>&dum, vector<int>&ans)
    {
        visi[start]=1;
        for(auto i:dum[start])
        {
            if(visi[i]==0)
            {
                dfs(i,visi,dum,ans);
            }
        }
        ans.push_back(start);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int>ans;
        vector<int>vis(numCourses,0);
        vector<int>visi(numCourses,0);
        vector<int>path(numCourses,0);
        vector<vector<int>>dum(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(prerequisites[j][0]==i)
                {
                    dum[i].push_back(prerequisites[j][1]);
                }
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(!cycle(i,vis,dum,ans,path))
                return false;
            }
        }
        // cout<<"Reach"<<endl;
        for(int i=0;i<numCourses;i++)
        {
            if(visi[i]==0)
            {
                dfs(i,visi,dum,ans);
            }
        }
        if(ans.size()==numCourses)
        return true;
        return false;
    }
};