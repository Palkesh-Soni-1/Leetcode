class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>m1,m2,m3,m4;
        for(int i=0;i<word1.length();i++)
        m1[word1[i]]++;
        for(int i=0;i<word2.length();i++)
        m2[word2[i]]++;
        if(m1.size()!=m2.size())
        return false;
        for(auto i:m1)
        {
            m3[i.second]++;
        }
        for(auto i:m2)
        {
            m4[i.second]++;
        }
        if(m3.size()!=m4.size())
        return false;
        for(int i=0;i<m3.size();i++)
        {
            if(m3[i]!=m4[i])
            return false;
        }
        for(auto i:m1)
        {
            if(m2.find(i.first)==m2.end())
            return false;
        }
        for(auto i:m2)
        {
            if(m1.find(i.first)==m1.end())
            return false;
        }
        return true;
    }
};