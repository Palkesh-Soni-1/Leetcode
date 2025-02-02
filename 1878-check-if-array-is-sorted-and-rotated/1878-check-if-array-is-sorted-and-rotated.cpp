class Solution {
public:
    bool check(vector<int>& nums) {
        int check = 0;
        int n = nums.size();
        if (nums[0] - nums[n-1] < 0)
            check++;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] < 0)
                check++;
        }
        if (check > 1)
            return false;
        else
            return true;
    }
};