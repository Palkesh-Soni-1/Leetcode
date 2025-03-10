class Solution {
    bool isvowel(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
        return false;
    }
public:
    long long solve(string word, int k) {
        int n = word.size();
        int left = 0;
        long long ans=0;
        int c = 0;
        unordered_map<char,int>v;
        for(int i=0;i<n;i++)
        {
            if(isvowel(word[i]))
            {
                v[word[i]]++;
            }
            else{
                c++;
            }
            while(v.size()==5&&c>=k)
            {
                ans+=(n-i);
                if(isvowel(word[left]))
                {
                    v[word[left]]--;
                    if(v[word[left]]==0)
                    v.erase(word[left]);
                }
                else{
                    c--;
                }
                left++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }
};