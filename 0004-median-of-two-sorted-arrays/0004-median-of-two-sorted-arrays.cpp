class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>temp(m+n);
        
        int i=0,j=0,k=0;
        while(i<n&&j<m)
        {
            if(nums1[i]<nums2[j])
            {
                temp[k++]=nums1[i++];
            }
            else{
                temp[k++]=nums2[j++];
            }
        }
        while(i<n)
        {
            temp[k++]=nums1[i++];
        }
        while(j<m)
        {
            temp[k++]=nums2[j++];
        }

        int z = temp.size();
        if(z%2)
        {
            return temp[z/2];
        }
        return (temp[z/2]+temp[(z-1)/2])/2.0;
    }
};