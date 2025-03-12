class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int f = lower_bound(nums.begin(), nums.end(), 1)-nums.begin();
        int pos = n-f;
        int f1 = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int neg = f1;
        return max(pos,neg);
    }
};