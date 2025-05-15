class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,length=0;
        int n = s.length();
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                start = max(start,mp[s[i]]+1); 
                // start = mp[s[i]]+1;
            }
            mp[s[i]]=i;
            end = i;
            length = max(length,end-start+1);
        }
        return length;
    }
};