class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int z = 1; z < n; z++) {
            int i = 0, j = z;
            vector<int> v;
            while (i < n & j < n) {
                // cout<<i<<" "<<j<<endl;
                v.push_back(a[i][j]);
                i++;
                j++;
            }
            sort(v.begin(), v.end());
            i = 0, j = z;
            int x=0;
            while (i < n & j < n) {
                ans[i][j] = v[x];
                x++;
                i++;
                j++;
            }
            // cout<<endl;
        }
        for (int z = 0; z < n; z++) {
            int i = z, j = 0;
            vector<int> v;
            while (i < n & j < n) {
                v.push_back(a[i][j]);
                i++;
                j++;
            }
            int x=0;
            sort(v.begin(), v.end(),greater<int>());
            i = z, j = 0;
            while (i < n & j < n) {
                ans[i][j] = v[x];
                x++;
                i++;
                j++;
            }
        }
        return ans;
    }
};