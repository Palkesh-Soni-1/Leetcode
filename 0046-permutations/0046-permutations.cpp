class Solution {
    void calculate(vector<int> nums, vector<vector<int>>& ans, vector<int>& ds,map<int, int>& mp) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mp[i] != 1) {
                ds.push_back(nums[i]);
                mp[i] = 1;
                calculate(nums, ans, ds, mp);
                mp[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        map<int, int> mp;
        vector<vector<int>> ans;
        vector<int> ds;
        calculate(nums, ans, ds, mp);
        return ans;
    }
};