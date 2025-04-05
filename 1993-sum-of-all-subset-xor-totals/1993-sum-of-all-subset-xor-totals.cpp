class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int total = 1 << n;
        int ans = 0;

        for (int mask = 0; mask < total; ++mask) {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subset.push_back(arr[i]);
                }
            }
            int r = 0;
            for (int num : subset)
                r = r ^ num;
            ans = ans + r;
        }
        return ans;
    }
};