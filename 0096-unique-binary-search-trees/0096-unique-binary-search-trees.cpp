class Solution {
public:
    unsigned long int binomialCoeff(unsigned int n, unsigned int k) {
        unsigned long int res = 1;

        // Since C(n, k) = C(n, n-k)
        if (k > n - k)
            k = n - k;

        // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }
    unsigned long int catalan(unsigned int n) {
        // Calculate value of 2nCn
        unsigned long int c = binomialCoeff(2 * n, n);

        // return 2nCn/(n+1)
        return c / (n + 1);
    }
    unsigned long int countBST(unsigned int n) {
        // find nth catalan number
        unsigned long int count = catalan(n);

        // return nth catalan number
        return count;
    }
    int numTrees(int n) {

        // Catalan numbers 2n! / (n+1)!*n!
        int ans = countBST(n);
        return ans;
    }
};