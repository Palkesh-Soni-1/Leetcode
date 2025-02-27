class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto i : arr) {
            mp[i]++;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int count = 0;
                if (arr[i] == 1 && arr[j] == 2)
                    count = 2;
                int prev = arr[j];
                long long int x = arr[i] + arr[j];
                int flag = 1;
                int y = 0;
                while (flag) {
                    if (mp.find(x) != mp.end()) {
                        if(y==0)
                        {
                            count=2;
                            y=1;
                        }
                        count++;
                        long long int temp = x;
                        x += prev;
                        prev = temp;
                    } else {
                        flag = 0;
                        break;
                    }
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};