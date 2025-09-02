class Solution {

public:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int n = points.size();
        int count = 0;
        for (vector<int>& point : points) {
            // cout << point[0] << point[1] << "\n";
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1]) {
                    bool between = false;
                    for (int k = i + 1; k < j; k++) {
                        if (points[k][1] <= points[i][1] &&
                            points[k][1] >= points[j][1]) {
                            between = true;
                            break;
                        }
                    }
                    if (!between) {
                        cout << points[i][0] << points[j][0] << "\n";
                        count++;
                    }
                }
            }
        }

        return count;
    }
};