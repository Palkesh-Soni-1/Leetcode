class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i=14;i>=0;i--)
        {
            long long int x = pow(3,i);
            if(n-x>=0)
            n-=x;
            if(n==0)
            return true;
        }
        return false;
    }
};