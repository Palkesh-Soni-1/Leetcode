class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(n<k)
        {
            return 0;
        }
        if(k==1)
        return max(cardPoints[0], cardPoints[n-1]);
        int x = n-k;
        int ans=0;
        int l = x;
        int r = (l+k);
        int temp=0;
        for(int i=l;i<r;i++)
        {
            int z = i%n;
            temp+=cardPoints[z];
        }
        ans = temp;
        x = (x+1)%n;
        r = (x+k-1)%n;
        cout<<temp<<endl;
        while((x%n)!=1)
        {
            int point =0;
            point  = temp-cardPoints[l]+cardPoints[r];
            l = x;
            x = (x+1)%n;
            r = (x+k-1)%n;
            temp = point;
            cout<<temp<<endl;
            ans = max(point,ans);
        }
        return ans;
    }
};