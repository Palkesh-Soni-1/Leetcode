class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>prob(n+1,0.0);
        prob[0]=1.0;
        double currProb = (k)?1:0;
        for(int i=1;i<=n;i++)
        {
            prob[i]=currProb/maxPts;

            if(i<k)
            {
                currProb+=prob[i];
            }

            if(i-maxPts>=0&&i-maxPts<k)
            currProb-=prob[i-maxPts];
            // for(int j=1;j<=maxPts;j++)
            // {
            //     if(i-j>=0&&i-j<k)
            //     {
            //         prob[i] = prob[i]+prob[i-j]/maxPts;
            //         cout<<prob[i]<<endl;
            //     }
            // }
        }

        double ans=0;
        for(int i=k;i<=n;i++)
        {
            ans+=prob[i];
        }
        return ans;
    }
};