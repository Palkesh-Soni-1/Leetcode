class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> temp;
        for (int i = 0; i <= digits.size() - 3; i++) {
            for (int j = i + 1; j <= digits.size() - 2; j++) {
                for (int k = j + 1; k <= digits.size() - 1; k++) {
                    int n1 = digits[i] * 100 + digits[j] * 10 + digits[k];
                    int n2 = digits[i] * 100 + digits[k] * 10 + digits[j];
                    int n3 = digits[j] * 100 + digits[i] * 10 + digits[k];
                    int n4 = digits[j] * 100 + digits[k] * 10 + digits[i];
                    int n5 = digits[k] * 100 + digits[i] * 10 + digits[j];
                    int n6 = digits[k] * 100 + digits[j] * 10 + digits[i];
                    if (n1 >= 100&&n1%2==0)
                        temp.insert(n1);
                    if (n2 >= 100&&n2%2==0)
                        temp.insert(n2);
                    if (n3 >= 100&&n3%2==0)
                        temp.insert(n3);
                    if (n4 >= 100&&n4%2==0)
                        temp.insert(n4);
                    if (n5 >= 100&&n5%2==0)
                        temp.insert(n5);
                    if (n6 >= 100&&n6%2==0)
                        temp.insert(n6);
                }
            }
        }
        vector<int>ans;
        for(auto i: temp)
        {
            ans.push_back(i);
        }
        return ans;
    }
};