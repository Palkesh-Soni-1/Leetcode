class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                swap( matrix[i][j],matrix[j][i]);
            }
        }
        for(int j=0;j<n/2;j++)
        {
            for(int i=0;i<n;i++)
            {
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};