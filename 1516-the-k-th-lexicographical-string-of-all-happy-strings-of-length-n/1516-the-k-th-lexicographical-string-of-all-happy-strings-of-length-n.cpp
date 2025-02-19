class Solution {
public:
    void solve(char s, int n, string final, set<string>&v)
    {
        // cout<<"final-: "<<final<<endl;
        if(n==0)
        {
            v.insert(final);
            return;
        }
        if(s=='a')
        {
            solve('b',n-1,final+"a",v);
            solve('c',n-1,final+"a",v);
        }
        if(s=='b')
        {
            solve('a',n-1,final+"b",v);
            solve('c',n-1,final+"b",v);
        }
        if(s=='c')
        {
            solve('a',n-1,final+"c",v);
            solve('b',n-1,final+"c",v);
        }
    }
    string getHappyString(int n, int k) {
        string ans="";
        int x = pow(2,n-1);
        if(k>(x*3))
        return ans;
        set<string>v;
        solve('a',n,"",v);
        solve('b',n,"",v);
        solve('c',n,"",v);
        // for(auto i:v)
        // cout<<i<<" ";
        // cout<<endl;
        string y = *std::next(v.begin(), k-1);
        return y;
    }
};