class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int temp=0;
        int n = num.size();
        if(n<3)
        return ans;
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i]==num[i+1]&&num[i]==num[i+2])
            {
                string t(3,num[i]);
                int x = stoi(t);
                if(x>=temp)
                {
                    temp=x;
                    ans=t;
                }
            }
        }
        return ans;
    }
};