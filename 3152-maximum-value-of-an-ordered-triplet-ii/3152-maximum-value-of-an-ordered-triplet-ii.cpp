class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        
        long long max_left = nums[0];
        long long max_diff = LLONG_MIN;
        long long result = 0;
        
        for (int j = 1; j < n - 1; j++) {
            max_diff = max(max_diff, max_left - nums[j]);
            result = max(result, max_diff * 1LL * nums[j + 1]);
            max_left = max(max_left, nums[j]*1LL);
        }
        
        return result;
    }
};