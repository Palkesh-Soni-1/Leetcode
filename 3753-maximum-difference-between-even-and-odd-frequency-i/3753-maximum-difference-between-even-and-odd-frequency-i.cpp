class Solution {
public:
    int maxDifference(string s) {
        vector<int>frequency(26,0);
        for(auto i:s)
        {
            frequency[i-'a']++;
        }
        int maxo=0;
        int mine=INT_MAX;
        for(auto i:frequency)
        {
            if(i%2)
            {
                maxo=max(maxo, i);
            }
            else if(i!=0){
                mine = min(mine, i);
            }
        }
        return maxo-mine;
    }
};