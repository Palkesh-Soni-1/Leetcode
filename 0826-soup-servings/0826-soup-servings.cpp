class Solution {
public:
    vector<vector<double>> serving;

    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (serving[a][b] >= 0) return serving[a][b];

        double result = 0.25 * (
            dfs(a - 4, b) +
            dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) +
            dfs(a - 1, b - 3)
        );

        return serving[a][b] = result;
    }

    double soupServings(int n) {
        if (n > 4800) return 1.0; 

        int N = (n + 24) / 25; 
        serving = vector<vector<double>>(N + 1, vector<double>(N + 1, -1));
        return dfs(N, N);
    }
};