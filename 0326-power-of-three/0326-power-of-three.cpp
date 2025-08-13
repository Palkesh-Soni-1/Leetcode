class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0||n==2)
        return false;
        if(n==1)
        return true;

        int x=n;
        double y = n;
        
        while(n>3)
        {
            x = n/3;
            y = n/3.0;
            if(x==y&&x%3==0);
            else{
                return false;
            }
            n = n/3;
        }
        return true;
    }
};