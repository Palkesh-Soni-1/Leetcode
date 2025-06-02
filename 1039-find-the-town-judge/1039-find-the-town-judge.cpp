class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        vector<int>ans;
        int size = trust.size();
        for(int i=0;i<size;i++)
        {
            int u = trust[i][0];
            int v = trust[i][1];
            indegree[v]++;
            outdegree[u]++;
        }
        for(int i=1;i<n+1;i++)
        {
            if(indegree[i]==n-1&&outdegree[i]==0)
            ans.push_back(i);
        }
        if(ans.size()==1)
        return ans[0];
        return -1;
    }
};