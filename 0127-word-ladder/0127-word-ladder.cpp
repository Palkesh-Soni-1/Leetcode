class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<int>vis(n,0);
        vector<string>ans;
        int exist=0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int an;
        while(!q.empty())
        {
            auto x = q.front();
            string s = x.first;
            // cout<<s<<endl;
            int le = x.second;
            q.pop();
            if(s==endWord)
            {
                exist=1;
                an = le;
                break;
            }
            for(int i=0;i<n;i++)
            {
                string a = wordList[i];
                // cout<<"a "<<a<<endl;
                if(vis[i]==0)
                {
                    // cout<<"check"<<endl;
                    if(a==s)
                    {
                        vis[i]=1;
                    }
                    else{
                        int cnt=0;
                        // cout<<cnt<<endl;
                        int len = a.length();
                        for(int j=0;j<len;j++)
                        {
                            // cout<<j<<endl;
                            if(s[j]!=a[j])
                            cnt++;
                        }
                        if(cnt==1)
                        {
                          q.push({a,le+1});
                            vis[i]=1;
                        }
                    }
                }
            }
        }
        if(exist)
        {
            return an;
        }
        return 0;
    }
};