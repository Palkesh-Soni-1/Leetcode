class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();
        int m = pattern.length();
        vector<string>ans;

        for(int i=0;i<n;i++)
        {
            string s = words[i];
            map<char,char>mp1,mp2;
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(mp1.find(s[j])==mp1.end()&&mp2.find(pattern[j])==mp2.end())
                {
                    mp1[s[j]]=pattern[j];
                    mp2[pattern[j]]=s[j];
                }
                else{
                    if(mp1[s[j]]!=pattern[j]||mp2[pattern[j]]!=s[j])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};