class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       int m = nums2.size();
       int num3=0;
       if(m%2)
       {
        for(int i=0;i<n;i++)
        {
            num3 = num3^nums1[i];
        }
       }
       int num4=0;
       if(n%2)
       {
        for(int i=0;i<m;i++)
        {
            num4 = num4^nums2[i];
        }
       }
    return num3^num4;
    }
};