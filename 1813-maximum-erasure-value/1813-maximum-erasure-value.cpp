class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        unordered_map<int, int> mp;
        int ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (mp.find(nums[r]) != mp.end()) {
                l = max(l, mp[nums[r]]);
            }

            mp[nums[r]] = r + 1;
            ans = max(ans, presum[r + 1] - presum[l]);
        }

        return ans;
    }
};
