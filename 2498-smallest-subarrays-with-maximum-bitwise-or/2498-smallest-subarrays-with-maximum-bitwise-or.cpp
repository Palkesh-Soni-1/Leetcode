class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> setBitIndex(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            int endIndex = i;
            for (int j = 0; j < 32; j++) {
                if (!(nums[i] & (1 << j))) {
                    if (setBitIndex[j] != -1) {
                        endIndex = max(endIndex, setBitIndex[j]);
                    }
                } else {
                    setBitIndex[j] = i;
                }
            }
            res[i] = endIndex - i + 1;
        }
        return res;
    }
};
