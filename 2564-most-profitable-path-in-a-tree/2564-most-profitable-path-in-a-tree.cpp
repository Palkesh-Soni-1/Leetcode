// class Solution {

//     void dfs(int node ,map<int,vector<int>>&adj, vector<int>&ans, int alice ,vector<int>& amount){
//         if(!adj.count(node)){
//             ans.push_back(alice+amount[node]);
//             return ;
//         }

//         alice = alice + amount[node];

//         for(auto i : adj[node]){
//             dfs(i,adj,ans,alice,amount);
//         }

//         return ;
//     }
// public:
//     int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
//     //     map<int,vector<int>>adj;
//     //    map<int,int>parent;
//     //    for(auto i : edges){
//     //     adj[i[0]].push_back(i[1]);
//     //     parent[i[1]] = i[0];
//     //    }
//     vector<vector<int>>adj(n);
//     for(auto i: edges)
//     {
//         ad
//     }
//         vector<int>vis(n,0);
//         vis[0]=-1;
//         queue<int>q;
//         q.push(0);
//         while(!q.empty())
//         {
//             int x = q.front();
//             q.pop();

//         }


//        vector<int>path;

//        while(bob != 0){
//         path.push_back(bob);
//         bob = parent[bob];
//        }
//        path.push_back(bob);

//        if(path.size() %2 == 0){
//         for(int i=0; i<path.size()/2; i++){
//             amount[path[i]] = 0;
//         }
//        }
//        else{
//         int i;
//             for( i=0; i<path.size()/2; i++){
//                 amount[path[i]] = 0;
//             }
//             amount[i] = amount[i]/2;
//        }

//         int alice = 0;
//         vector<int>ans;
//        dfs(0,adj,ans,alice,amount);

//     //    sort(ans.begin(), ans.end());
//     int final = INT32_MIN;
//     for(auto i:ans)
//     {
//         if(i>=final)
//         final = i;
//     }
//        return final;
//     }
// };

class Solution {
public:
    int dfs(vector<vector<int>>&adj, int node, int t, map<int,int>&visited, vector<int>&amount) {
        int currVal = amount[node];
        if (visited.count(node)) {
            if (visited[node] < t) currVal = 0;
            else if (visited[node] == t) currVal /= 2;
        }
        if (adj[node].size() == 0) return currVal;
        int res = INT_MIN;
        for (auto nbr : adj[node]) {
            res = max(res, dfs(adj, nbr, t+1, visited, amount));
        }
        return currVal + res;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n, vector<int>());
        vector<vector<int>> tree(n, vector<int>());
        vector<int> parent(n, 0);

        for (int i = 0; i < n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> added(n, 0);
        queue<int> q;
        q.push(0);
        added[0] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nbr : adj[node]) {
                if (!added[nbr]) {
                    added[nbr]++;
                    tree[node].push_back(nbr);
                    q.push(nbr);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto child : tree[i]) {
                parent[child] = i;
            }
        }

        map<int, int> visited;
        int t = 0;
        int node = bob;
        while (node != 0) {
            visited[node] = t++;
            node = parent[node];
        }
        return dfs(tree, 0, 0, visited, amount);
    }
};