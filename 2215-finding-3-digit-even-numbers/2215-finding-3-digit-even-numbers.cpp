class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> temp;
        for (int i = 0; i <= digits.size() - 3; i++) {
            for (int j = i + 1; j <= digits.size() - 2; j++) {
                for (int k = j + 1; k <= digits.size() - 1; k++) {
                    if (digits[i] > 0 && digits[k] % 2 == 0) {
                        int n1 = digits[i] * 100 + digits[j] * 10 + digits[k];
                        temp.insert(n1);
                    }
                    if (digits[i] > 0 && digits[j] % 2 == 0) {
                        int n2 = digits[i] * 100 + digits[k] * 10 + digits[j];
                        temp.insert(n2);
                    }
                    if (digits[j] > 0 && digits[k] % 2 == 0) {
                        int n3 = digits[j] * 100 + digits[i] * 10 + digits[k];
                        temp.insert(n3);
                    }
                    if (digits[j] > 0 && digits[i] % 2 == 0) {
                        int n4 = digits[j] * 100 + digits[k] * 10 + digits[i];
                        temp.insert(n4);
                    }
                    if (digits[k] > 0 && digits[j] % 2 == 0) {
                        int n5 = digits[k] * 100 + digits[i] * 10 + digits[j];
                        temp.insert(n5);
                    }
                    if (digits[k] > 0 && digits[i] % 2 == 0) {
                        int n6 = digits[k] * 100 + digits[j] * 10 + digits[i];
                        temp.insert(n6);
                    }
                }
            }
        }
        vector<int> ans;
        for (auto i : temp) {
            ans.push_back(i);
        }
        return ans;
    }
};