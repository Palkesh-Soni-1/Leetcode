class Solution {
public:
    int M = 1e9+7;
    long long power(long long b, long long e, long long ans) {
        if(e == 0) return ans;
        if(e & 1) return power(b, e - 1, (ans * b) % M);
        else return power((b * b) % M, e / 2, ans);
    }
    int countGoodNumbers(long long n) {
        // int even = n/2 ;
        int m = int(1e9) + 7;
        // int odd = n-even;
        // long long int b=1;
        // if(odd!=0)
        // b = pow(4,odd);
        // b = b%m;
        // long long int a = pow(5,even);
        // a = a%m;
        // int ans = (a*b)%m;
        long long temp = power(20, n/2, 1);
        return (n & 1) ? (temp * 5) % M : temp;
        // long long ans = 1;
        // for (int i = 0; i < n / 2; i++) {
        //     ans = (ans % m * 20 % m) % m;
        // }
        // if (n % 2) {
        //     ans = (ans%m * 5%m)%m;
        // } 
        // return ans % m;
    }
};