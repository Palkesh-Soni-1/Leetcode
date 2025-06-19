class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";
        string temp = "";
        int flag = false;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                // cout<<temp<<" "<<temp.length()<<endl;
                if (temp.length() > 0) {
                    reverse(temp.begin(), temp.end());
                    if (flag) {
                        ans += " ";
                    }
                    flag = true;
                    ans += temp;
                }
                temp = "";
            } else {
                temp += s[i];
            }
        }
        if (temp.length() > 0) {
            reverse(temp.begin(), temp.end());
            if (flag) {
                ans += " ";
            }
            ans += temp;
        }
        return ans;
    }
};