class Solution {
public:
    int minMaxDifference(int num) {
        char toChange='9';
        string s = to_string(num);
        string s1 = to_string(num);
        char toChange1=s1[0];
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='9')
            {
                toChange=s[i];
                break;
            }
        }
        int max=num;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==toChange)
            {
                s[i]='9';
            }
        }
        int min=num;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==toChange1)
            {
                s1[i]='0';
            }
        }
        max = stoi(s);
        min = stoi(s1);
        return max-min;
    }
};