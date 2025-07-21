class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        int n = s.length();
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                count++;
                ans+=s[i];
            }
            else if(s[i]==s[i-1])
            {
                count++;
                if(count>=3)
                continue;
                else{
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
                count=1;
            }
        }
        return ans;
    }
};