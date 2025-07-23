class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        long long totalPoints = 0;

        vector<char> stack1;
        for (char c : s) {
            if (c == 'b' && !stack1.empty() && stack1.back() == 'a') {
                stack1.pop_back();
                totalPoints += x;
            } else {
                stack1.push_back(c);
            }
        }

        vector<char> stack2;
        for (char c : stack1) {
            if (c == 'a' && !stack2.empty() && stack2.back() == 'b') {
                stack2.pop_back();
                totalPoints += y;
            } else {
                stack2.push_back(c);
            }
        }

        return totalPoints;
    }
};