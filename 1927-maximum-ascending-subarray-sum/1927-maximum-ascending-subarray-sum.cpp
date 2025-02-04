class Solution {
public:
    int maxAscendingSum(vector<int>& a) {
        int sum=a[0];
        int ans=a[0];
        int n = a.size();
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            sum+=a[i];
            else
            sum=a[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};