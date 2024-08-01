class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int count=0;
        for(int j=0;j<n;j++)
        {
            string s = details[j];
            int a = s[11];
            int b = s[12];
            int c = (b-48)+(a-48)*10;
            if(c>60)
            {
                count++;
            }
        }
        return count;
    }
};