class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int ver = edges.size()+1;
        vector<int>count(ver+1,0);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            count[u]++;
            count[v]++;
            if(count[u]==ver-1)
            return u;
            if(count[v]==ver-1)
            return v;
        }
        return -1;
    }
};