class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(baskets[j]>=fruits[i]&&vis[j]==0)
                {
                    vis[j]=1;
                    count++;
                    break;
                }
            }
        }
        return n-count;
    }
};