class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int ans = 1;
        char c = chars[0];
        int ind = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (chars[i] == c) {
                cnt++;
            } else {
                chars[ind] = c;
                ind++;
                c = chars[i];
                if (cnt > 1) {
                    string temp = to_string(cnt);
                    for (int i = 0; i < temp.length(); i++) {
                        chars[ind] = temp[i];
                        ind++;
                        ans++;
                    }
                }
                cnt = 1;
                ans++;
            }
        }
        chars[ind] = c;
        ind++;
        if (cnt > 1) {
            string temp = to_string(cnt);
            for (int i = 0; i < temp.length(); i++) {
                chars[ind] = temp[i];
                ind++;
                ans++;  
            }
        }
        cout << ans << endl;
        return ans;
    }
};