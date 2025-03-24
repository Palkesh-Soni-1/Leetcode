class Solution {
public:
    void power1(double x, long long n, double &ans) {
        if(n==0)
        {
            return;
        }
        if (n % 2) {
            ans *= x;
            n = n - 1;
        } 
        power1(x*x, n / 2, ans);
    }
    double myPow(double x, int n) {
        double ans = 1;
        long long p = n;
        power1(x, abs(p), ans);
        if (n < 0)
            return 1.0 / ans;
        return ans;
    }
};