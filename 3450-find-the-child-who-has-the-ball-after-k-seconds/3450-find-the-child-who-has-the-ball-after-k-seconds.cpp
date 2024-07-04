class Solution {
public:
    int numberOfChild(int n, int k) {
        int x = (k)/(n-1);
        int y = k%(n-1);
        int ans;
        if(x%2)
        {
            ans = (n-1)-y;
        }
        else
        ans = y;
        return ans;
    }
};