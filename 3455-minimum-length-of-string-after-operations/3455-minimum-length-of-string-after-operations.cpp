class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int ans=0;
        for(auto i:mp)
        {
            int x = i.second;
            if(x>3)
            {
                while(x>3)
                {
                    x =x-2;
                }
                if(x==3)
                ans=ans+1;
                else
                ans=ans+2;
            }
            else if(x==3)
            ans=ans+1;
            else
            ans=ans+x;
        }
        return ans;
    }
};