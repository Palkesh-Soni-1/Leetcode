class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int>mp;
        int count=0;
        for(auto i: dominoes)
        {
            if(i[0]>i[1]) swap(i[0],i[1]);
            count+=mp[{i[0],i[1]}]++;
        }
        return count;
    }
};