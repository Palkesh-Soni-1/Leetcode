class Solution {
public:
    string removeOccurrences(string s, string part) {
        string a = s;
        int n = s.length();
        int m = part.length();
        // cout<<n<<" "<<m<<endl;
        for(int i=0;i<=n-m;i++)
        {
            if(a[i]==part[0])
            {
                // cout<<"YES1"<<endl;
                int k=i;
                int flag=1;
                for(int j=0;j<m;j++)
                {
                    if(a[k]!=part[j])
                    {
                        flag=0;
                        break;
                    }
                    k++;
                    cout<<"YES2"<<endl;
                }
                if(flag)
                {
                    a.erase(i,m);
                    n = a.length();
                    cout<<a<<endl;
                    i=-1;
                }
            }
        }
        return a;
    }
};