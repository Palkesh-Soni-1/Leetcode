class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, r=0;
        int ans=0;
        int len = fruits.size();
        unordered_map<int,int>mp;
        while(r<len)
        {
            mp[fruits[r]]++;
            if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                    i++;
                }
            }
            ans = max(ans, r-i+1);
            r++;
        }
        return ans;
    }
};