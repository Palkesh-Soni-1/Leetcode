class Solution {

    bool isVowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int cnt=0;
        int ans=0;
        int i=0;
        int j=k;
        int n = s.length();
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))
            cnt++;
        }
        ans=max(ans,cnt);
        while(j<n)
        {
            if(isVowel(s[j]))
            cnt++;
            if(isVowel(s[i]))
            cnt--;
            i++;
            j++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};