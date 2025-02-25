class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //prefix sum approch
        long long int n = arr.size();
        long long int presum=0, oddcnt=0;
        for(auto i:arr)
        {
            presum+=i;
            if(presum%2)
            oddcnt++;
        }
        oddcnt+=(n-oddcnt)*oddcnt;
        return oddcnt%1000000007;
    }
};