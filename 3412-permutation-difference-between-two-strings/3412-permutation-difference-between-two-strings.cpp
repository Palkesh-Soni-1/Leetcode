class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s[i]==t[j])
                {
                    sum+=(abs(i-j));
                }
            }
        }
        return sum;
    }
};