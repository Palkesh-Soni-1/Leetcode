class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> s;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            int temp = 1;
            while (!s.empty()) {
                if (s.top().first <= temperatures[i]) {
                    s.pop();
                } else {
                    temp = s.top().second;
                    break;
                }
            }
            if (s.empty())
                ans.push_back(0);
            else {
                ans.push_back(temp - i);
            }
            s.push({temperatures[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};