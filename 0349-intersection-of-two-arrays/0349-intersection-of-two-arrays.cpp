class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n&&j<m)
        {
            if(nums1[i]==nums2[j])
            {
                int last;
                if(ans.size())
                last = ans.back();
                if(last==nums1[i]);
                else{
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};