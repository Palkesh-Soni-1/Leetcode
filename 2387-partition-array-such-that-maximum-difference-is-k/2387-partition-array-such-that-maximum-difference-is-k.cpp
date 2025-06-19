class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        set<int> unique(nums.begin(), nums.end());
        vector<int> sorted(unique.begin(), unique.end());

        int ans = 1;
        int minVal = sorted[0];

        for (int i = 1; i < sorted.size(); i++) {
            if (sorted[i] - minVal > k) {
                ans++;
                minVal = sorted[i];
            }
        }
        return ans;
    }
};