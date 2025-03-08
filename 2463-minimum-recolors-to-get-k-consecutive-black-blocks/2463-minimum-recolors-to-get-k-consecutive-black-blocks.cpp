class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int val=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')
            val++;
        }
        int p1=0;
        int p2=k;
        int ans=val;
        while(p2<blocks.size())
        {
            if(blocks[p1]=='W'&&blocks[p2]=='W')
            {
                p1++;
                p2++;
            }
            if(blocks[p1]=='W'&&blocks[p2]=='B'){
                val--;
                p1++;
                p2++;
                ans=min(ans,val);
            }
            if(blocks[p1]=='B'&&blocks[p2]=='B'){
                p1++;
                p2++;
            }
            if(blocks[p1]=='B'&&blocks[p2]=='W'){
                val++;
                p1++;
                p2++;
                ans=min(ans,val);
            }
        }
        return ans;
    }
};