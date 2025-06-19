class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>result;
        int n = candies.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(candies[i],maxi);
        }
        for(int i=0;i<n;i++)
        {
            int temp = candies[i]+extraCandies;
            if(temp>=maxi)
            {
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }
        return result;
    }
};