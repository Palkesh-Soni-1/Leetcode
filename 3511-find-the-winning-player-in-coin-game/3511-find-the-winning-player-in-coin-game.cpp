class Solution {
public:
    string losingPlayer(int x, int y) {
        int i=0;
        while(x>0&&y>3)
        {
            i++;
            x--;
            y = y-4;
        }
        string ans;
        if(i%2)
        ans="Alice";
        else
        ans = "Bob";
        return ans;
        
    }
};