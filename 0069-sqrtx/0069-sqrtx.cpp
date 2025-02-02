class Solution {
public:
    int mySqrt(int x) {
        int low = 1;
        int high = x;
        int ans=0;
        while(low<=high)
        {
            long long int mid = low+(high-low)/2;
            if(mid*mid == x)
            return mid;
            if(mid*mid>x)
            {
                high = mid-1;
            }
            else if(mid*mid<x)
            {
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};