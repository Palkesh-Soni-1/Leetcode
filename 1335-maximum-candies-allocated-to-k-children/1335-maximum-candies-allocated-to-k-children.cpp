class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, candies[i]);
        }
        int ans = 0;
        int l = 1, h = maxi;
        sort(candies.begin(), candies.end(), greater<int>());
        while (l <= h) {
            int mid = (l)+(h-l)/2;
            long long count = 0;
            for (int j = 0; j < n; j++) {
                count += (candies[j] / mid);
            }
            if (count >= k) {
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};