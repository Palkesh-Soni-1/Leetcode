class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k)
        {
            string temp="";
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='z')
                temp+='a';
                else{
                    temp+=s[i]+1;
                }
            }
            s+=temp;
        }
        return s[k-1];
    }
};