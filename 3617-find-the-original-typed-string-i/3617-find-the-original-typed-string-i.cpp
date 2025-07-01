class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int l = 0;
        for(int i=0;i<n-1;i++)
        {
            if(word[i]==word[i+1])
            l++;
        }
        return l+1;
    }
};