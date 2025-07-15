class Solution {

    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        return false;
    }
    bool isConsonant(char c)
    {
        int t = c-'a';
        // cout<<t<<endl;
        if(t>=0&&t<=25)
        return true;
        return false;
    }
public:
    bool isValid(string word) {
        int length = word.length();
        if(length<3)
        return false;
        int c=0,v=0;        
        for(int i=0;i<length;i++)
        {
            // cout<<i<<endl;
            if(isdigit(word[i]));
            else if(isVowel(tolower(word[i])))
            v++;
            else if(isConsonant(tolower(word[i])))
            c++;
            else
            return false;
        }
        cout<<c<<" "<<v<<endl;
        if(c>=1&&v>=1)
        return true;
        return false;
    }
};