class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count=0;
        int flag=0;
        for(auto i:text)
        {
            if(i==' ')
            {   
                if(!flag)
                count++;
                flag=0;
                continue;
            }
            for(auto j:brokenLetters)
            {
                if(i==j)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(!flag)
        count++;
        return count;
    }
};