class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r,d;
        int n = senate.length();
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
            r.push(i);
            else{
                d.push(i);
            }
        }
        char ans='R';
        while(!r.empty()&&!d.empty())
        {
            int ra = r.front();
            r.pop();
            int di = d.front();
            d.pop();
            if(ra<di)
            r.push(ra+n);
            else{
                d.push(di+n);
            }
        }
        if(r.size())
        return "Radiant";
        else
        return "Dire";
    }
};