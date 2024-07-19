class Solution {
public:
    int myAtoi(string s) {
        int l = s.length();
        int k = 1;
        int ne = 0;
        string ans = "";
        int z = 1;
        for (int i = 0; i < l; i++) {
            if (k && z && s[i] == ' ')
                ;
            else if ((!z || !k) && s[i] == ' ')
                break;
            else if (k && z && s[i] == '-') {
                ne++;
                z = 0;
            } else if (k && z && s[i] == '+')
                z = 0;
            else if (k && s[i] == '0')
                z = 0;
            else if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' ||
                     s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' ||
                     s[i] == '8' || s[i] == '9') {
                k = 0;
                ans = ans + s[i];
            } else {
                break;
            }
        }
        // cout<<ans <<" "<<typeid(ans).name<<endl;
        if (ans.length() == 0)
            return 0;
        int cnt = 0;
        int cnt1=0;
        if (ans.length() == 10) {
             if (int(ans[0]) - 48 > 2)
             {
                if(ne)
                return INT_MIN;
                return INT_MAX;
             }
            if (int(ans[0]) - 48 == 2)
            cnt1++;
            if (int(ans[1]) - 48 > 1&&cnt1==1)
                return INT_MAX;
            if (int(ans[1]) - 48 == 1)
            cnt1++;
            if (int(ans[2]) - 48 > 4&&cnt1==2)
                return INT_MAX;
            if (int(ans[2]) - 48 == 4)
            cnt1++;
            if (int(ans[3]) - 48 > 7 &&cnt1==3)
                return INT_MAX;
            if (int(ans[3]) - 48 ==7)
            cnt1++;
            if (int(ans[4]) - 48 >4&&cnt1==4)
                return INT_MAX;
            if (int(ans[4]) - 48 == 4)
            cnt1++;
            if (int(ans[5]) - 48 >8&&cnt1==5)
                return INT_MAX;
            if (int(ans[5]) - 48 == 8)
            cnt1++;
            if (int(ans[6]) - 48 >3&&cnt1==6)
                return INT_MAX;
            if (int(ans[6]) - 48 == 3)
            cnt1++;
            if (int(ans[7]) - 48 >6&&cnt1==7)
                return INT_MAX;
            if (int(ans[7]) - 48 ==6)
            cnt1++;
            if (int(ans[8]) - 48 >4&&cnt1==8)
                return INT_MAX;
            if (int(ans[8]) - 48 == 4)
            cnt1++;
            if ((int(ans[9]) - 48 >= 7) && ne == 0&&cnt1==9)
                return INT_MAX;
            if ((int(ans[9]) - 48 >= 8 ) && ne&&cnt1==9)
                return INT_MIN;
            // if (int(ans[0]) - 48 >= 2)
            //     cnt++;
            // if (int(ans[1]) - 48 >= 1 || cnt == 1)
            //     cnt++;
            // if (int(ans[2]) - 48 >= 4 || cnt == 2)
            //     cnt++;
            // if (int(ans[3]) - 48 >= 7 || cnt == 3)
            //     cnt++;
            // if (int(ans[4]) - 48 >= 4 || cnt == 4)
            //     cnt++;
            // if (int(ans[5]) - 48 >= 8 || cnt == 5)
            //     cnt++;
            // if (int(ans[6]) - 48 >= 3 || cnt == 6)
            //     cnt++;
            // if (int(ans[7]) - 48 >= 6 || cnt == 7)
            //     cnt++;
            // if (int(ans[8]) - 48 >= 4 || cnt == 8)
            //     cnt++;
            // if ((int(ans[9]) - 48 >= 7 || cnt == 9) && ne == 0)
            //     cnt++;
            // if ((int(ans[9]) - 48 >= 8  || cnt == 9) && ne)
            //     cnt++;
            // if (cnt == 10 && ne)
            //     return INT_MIN;
            // if (cnt == 10)
            // return INT_MAX;
            cout<<ans<<endl;
        }
        if (ans.length() > 10 && ne == 0) {
            return INT_MAX;
        } else if (ans.length() > 10 && ne)
            return INT_MIN;
            int ans1;
        if (ne)
        {
            cout<<ne<<endl;
            ans1 = stoi(ans);
            ans1 = - ans1;
            return ans1;
        }
        ans1 = stoi(ans);
        return ans1;
    }
};