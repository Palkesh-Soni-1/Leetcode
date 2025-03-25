class Solution {
long long N = 1000000007;
public:
    void power(long long int x, long long n, long  long int & ans)
    {
        if(n==0)
        return;
        if(n%2)
        {
            ans=(ans*x)%N;
            n = n-1;
        }
        power((x*x)%N, n/2, ans);
    }
    int countGoodNumbers(long long n) {
        long long int ans=1;
        power(20,n/2,ans);
        if(n%2)
        ans=(ans*5)%N;
        return ans%N;
    }
};