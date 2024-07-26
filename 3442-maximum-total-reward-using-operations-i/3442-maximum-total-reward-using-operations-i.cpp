class Solution {
public:
    int dp[2001][4001];
    int solve(vector<int>&r,int x,int ind){
        if(ind>=r.size()){
            return x;
        }
        if(dp[ind][x]!=-1){
            return dp[ind][x];
        }
        int npick=solve(r,x,ind+1);
        int pick=0;
        if(r[ind]>x){
            pick=solve(r,x+r[ind],ind+1);
        }
        return dp[ind][x]=max(pick,npick);
    }
    int maxTotalReward(vector<int>& r) {
        memset(dp,-1,sizeof(dp));
        sort(r.begin(),r.end());
        return solve(r,0,0);
    }
};