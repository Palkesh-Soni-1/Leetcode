class Solution {
public:
    int longestSubsequence(string s, int k) {
        int bits = 32 - __builtin_clz(k);
        int currentValue = 0;
        int length = 0;
        for (int i = 0; i < s.size(); i++) {
            char currentBit = s[s.size() - 1 - i];

            if (currentBit == '1') {
                if (i < bits && currentValue + (1 << i) <= k) {
                    currentValue += (1 << i);
                    length++;
                }
            } else {
                length++;
            }
        }

        return length;
    }
};