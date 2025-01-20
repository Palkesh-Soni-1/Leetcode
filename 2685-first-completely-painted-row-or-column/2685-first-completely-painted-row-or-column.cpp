class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        vector<int>a(n+1,0);
        for (int j = 0; j < n; j++) {
            a[arr[j]]=j;
        }
        int ans = n;
        int p = mat.size();
        int q = mat[0].size();
        for(int i=0;i<p;i++)
        {
            int x = -1;
            for(int j=0;j<q;j++)
            {
                x = max(a[mat[i][j]],x);
            }
            ans = min(ans,x);
        }
        for(int i=0;i<q;i++)
        {
            int x = -1;
            for(int j=0;j<p;j++)
            {
                x = max(a[mat[j][i]],x);
            }
            ans = min(ans,x);
        }
        return ans;
    }
};