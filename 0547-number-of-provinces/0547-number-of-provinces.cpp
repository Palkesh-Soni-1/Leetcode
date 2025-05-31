class Solution {
    void dfs(int node,vector<int>a[],vector<int>&V)
    {
        V[node]=1;
        for(auto i : a[node])
        {
            if(V[i]==0)
            {
                dfs(i,a,V);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>V(n+1,0);
        // V[0]=1;
        cout<<n<<endl;
        //creating adjacent list
        vector<int>a[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(V[i]==0)
            {
                count++;
                // V[i]=1;
                dfs(i,a,V);
            }
        }
        return count;
    }
};