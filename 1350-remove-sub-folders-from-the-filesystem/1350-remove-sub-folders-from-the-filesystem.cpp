class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // map<string,int>mp;
        // int n = folder.size();
        // vector<string>ans;
        // for(int i=0;i<n;i++)
        // {
        //     string s = folder[i];
        //     int m = s.size();
        //     string temp="";
        //     int flag=0;
        //     for(int j=0;j<m;j++)
        //     {
        //         temp+=s[j];
        //         if(mp.find(temp)!=mp.end())
        //         {
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(!flag)
        //     {
        //         mp[temp]++;
        //         ans.push_back(temp);
        //     }
        // }
        int n = folder.size();
        sort(folder.begin(), folder.end());
        vector<string>ans;
        string prev="";
        int i=0;
        while(i<n)
        {
            string s = folder[i];
            if(prev.empty() || s.substr(0,prev.length()+1)!=prev+'/')
            {
                ans.push_back(s);
                prev = s;
            }
            i++;
        }
        return ans;
    }
};