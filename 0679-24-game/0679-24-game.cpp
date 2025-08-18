class Solution {
    double ep = 0.1;
    bool solve(vector<double>&cards)
    {
        int n = cards.size();
        if(cards.size()==1)
        {
            return abs(cards[0]-24)<=ep;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                vector<double>temp;
                for(int k=0;k<n;k++)
                {
                    if(k!=i&&k!=j)
                    temp.push_back(cards[k]);
                }
                double a = cards[i];
                double b = cards[j];

                vector<double>express = {a+b, a-b, b-a, a*b};

                if(abs(a)>0.0)
                express.push_back(b/a);
                if(abs(b)>0.0)
                express.push_back(a/b);

                for(auto l:express)
                {
                    temp.push_back(l);
                    if(solve(temp))
                    return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();
        vector<double>temp1;
        for(int i=0;i<n;i++)
        temp1.push_back(1.0*cards[i]);
        return solve(temp1);
    }
};