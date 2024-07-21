class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        int n = s.length();
        vector<int> ind;
        vector<int>one;
        int flag1=0;
        for (int i = 0; i <n; i++) {

            if(s[i]=='0'&&flag1)
            {
                one.push_back(0);
                flag1=0;
            }
            else if (s[i] == '1')
            {
                ind.push_back(i);
                one.push_back(1);
                flag1=1;
            }
        }
        if(s[n-1]=='0')
        ind.push_back(n);
        else
        ind.push_back(n-1);
        // for(int i=0;i<ind.size();i++)
        // cout<<ind[i]<<" "; 
        // if(n==1)
        // return 0;
        // if(ind.size()==n)
        // return 0;
        int flag = 1;
        while (flag) {
            // for (int i = 0; i < ind.size() - 1; i++) {
            //     if (ind[i + 1] - ind[i] != 1) {
            //         ans++;
            //         ind[i] = ind[i + 1] - 1;
            //     }
            // }
            // for (int i = 0; i < ind.size() - 1; i++) {
            //     if (ind[i + 1] - ind[i] != 1) {
            //         flag = 1;
            //         break;
            //     }
                flag = 0;
            // }
        }
        int record=0;
        for(auto i:one)
        {
            if(i==1)
            {
                record++;
            }
            else{
                ans=ans+record;
            }
        }
        return ans;
    }
};