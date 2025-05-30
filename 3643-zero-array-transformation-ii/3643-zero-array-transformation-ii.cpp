class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        auto check = [&](int m) -> bool {
            vector<int> arr(n + 1, 0);
            for (int i = 0; i < m; ++i) {
                int start = queries[i][0], end = queries[i][1], val = queries[i][2];
                arr[start] += val;
                if (end + 1 < n) arr[end + 1] -= val;
            }
            
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                cur += arr[i];
                if (cur < nums[i]) return false;
            }
            return true;
        };
        
        if (!check(queries.size())) return -1;
        
        int l = 0, r = queries.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    }
};







// class Solution {
// public:
//     int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         int ans=0;
//         int m = queries.size();
//         for(int i=0;i<m;i++)
//         {
//             for(int j=queries[i][0];j<=queries[i][1];j++)
//             {
//                 nums[j]=max(0,nums[j]-queries[i][2]);
//             }
//             ans++;
//             int flag=1;
//             for(int j=0;j<n;j++)
//             {
//                 if(nums[j]!=0)
//                 {
//                     flag=0;
//                 }
//             }
//             if(flag)
//             return ans;
//         }
//         return -1;
//     }
// };