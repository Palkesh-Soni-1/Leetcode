class Solution {
    bool equals(string str1,string str2)
    {
        if(str1.length()!=str2.length())
        return false;
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]!=str2[i])
            return false;
        }
        return true;
    }

    bool startsWith(string str1,string str2)
    {
        for(int i=0;i<str2.length();i++)
        {
            if(str1[i]!=str2[i])
            return false;
        }
        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.length()>str1.length())
        return gcdOfStrings(str2, str1);
        if(equals(str1, str2))
        return str1;
        if(startsWith(str1,str2))
        return gcdOfStrings(str1.substr(str2.length()),str2);
        return "";
    }
};