class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char c : s)
        {
            if(isalnum(c)){
                result+=tolower(c);
            }
        }
        // cout<<result<<endl;
        int i=0;
        int j=result.length()-1;
        while(i<j)
        {
            if(result[i]!=result[j])
            {return false;}
            i++;
            j--;
        }
        return true;
    }
};