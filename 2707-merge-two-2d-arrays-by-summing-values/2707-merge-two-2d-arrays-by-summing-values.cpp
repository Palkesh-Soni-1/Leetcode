class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        while (i < n && j < m) {
            vector<int> temp;
            if (nums1[i][0] == nums2[j][0]) {
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1] + nums2[j][1]);
                ans.push_back(temp);
                i++;
                j++;
            } else if (nums1[i][0] > nums2[j][0]) {
                temp.push_back(nums2[j][0]);
                temp.push_back(nums2[j][1]);
                ans.push_back(temp);
                j++;
            } else {
                temp.push_back(nums1[i][0]);
                temp.push_back(nums1[i][1]);
                ans.push_back(temp);
                i++;
            }
        }
        while (i < n) {
            vector<int> temp;
            temp.push_back(nums1[i][0]);
            temp.push_back(nums1[i][1]);
            ans.push_back(temp);
            i++;
        }
        while (j < m) {
            vector<int> temp;
            temp.push_back(nums2[j][0]);
            temp.push_back(nums2[j][1]);
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};