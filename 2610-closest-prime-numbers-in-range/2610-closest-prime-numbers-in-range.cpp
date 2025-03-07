class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for (int i = left; i <= right; i++) {
            int flag = 0;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    flag = 1;
                    break;
                }
            }
            if (!flag && i != 1) {
                prime.push_back(i);
            }
        }
        int diff = right;
        int a = -1, b = -1;
        if (prime.size() >= 2) {

            for (int i = 0; i < prime.size() - 1; i++) {
                if ((prime[i + 1] - prime[i]) < diff) {
                    diff = prime[i + 1] - prime[i];
                    a = prime[i];
                    b = prime[i + 1];
                }
            }
        }
        return {a, b};
    }
};