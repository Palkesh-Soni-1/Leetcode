class Solution {
public:
    bool doesAliceWin(string s) {
        int vow = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                vow++;
        }
        if(vow==0)
        return false;
        return true;
    }
};