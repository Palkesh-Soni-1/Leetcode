class Solution {
public:
    int longestMonotonicSubarray(vector<int>& a) {
        int n = a.size();
        int count=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            count++;
            else
            count=1;
            ans=max(ans,count);
        }
        count=1;
        int ans1=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
            count++;
            else
            count=1;
            ans1=max(ans1,count);
        }
        return max(ans,ans1);
    }
};