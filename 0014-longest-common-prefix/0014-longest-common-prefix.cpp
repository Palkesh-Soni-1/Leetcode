class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m=INT_MAX;
        int n = strs.size();

        for(int i=0;i<n;i++)
        {
            if(strs[i].length()<m)
            m = strs[i].length();
        }
        string ans="";
        for(int i=0;i<m;i++)
        {
            int flag=false;
            for(int j=0;j<n-1;j++)
            {
                if(strs[j][i]!=strs[j+1][i])
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
            ans+=strs[0][i];
            else
            break;
        }
        return ans;
    }
};