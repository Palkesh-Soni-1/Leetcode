class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>m;
        vector<int>c;
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            m[A[i]]++;
            m[B[i]]++;
            if(m[A[i]]==2)
            count++;
            if(m[B[i]]==2&&A[i]!=B[i])
            count++;
            c.push_back(count);
        }
        return c;
    }
};