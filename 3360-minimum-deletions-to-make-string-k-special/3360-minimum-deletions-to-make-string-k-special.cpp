class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int n = word.size();
        for (int i = 0; i < n; i++) {
            freq[word[i] - 'a']++;
        }
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                int temp = 0;
                for (int j = 0; j < 26; j++) {
                    if (freq[j]) {
                        if (freq[i] > freq[j])
                            temp += freq[j];
                        else if (abs(freq[i] - freq[j]) > k) {
                            temp += abs(freq[j] - freq[i]) - k;
                        }
                    }
                }
                ans = min(ans, temp);
            }
        }
        return ans;
    }
};