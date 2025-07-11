class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0,j=0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(i<n1&&j<n2)
        {
            if(nums1[i]==nums2[j])
            {
                i++;
                j++;
                while(i<n1&&nums1[i-1]==nums1[i])
                i++;
                while(j<n2&&nums2[j-1]==nums2[j])
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                ans[0].push_back(nums1[i]);
                i++;
                while(i<n1&&nums1[i-1]==nums1[i])
                i++;
            }
            else
            {
                ans[1].push_back(nums2[j]);
                j++;
                while(j<n2&&nums2[j-1]==nums2[j])
                j++;
            }
        }
        while(i<n1)
        {
            ans[0].push_back(nums1[i]);
            i++;
            while(i<n1&&nums1[i-1]==nums1[i])
            i++;
        }
        while(j<n2)
        {
            ans[1].push_back(nums2[j]);
            j++;
            while(j<n2&&nums2[j-1]==nums2[j])
            j++;
        }
        return ans;
    }
};