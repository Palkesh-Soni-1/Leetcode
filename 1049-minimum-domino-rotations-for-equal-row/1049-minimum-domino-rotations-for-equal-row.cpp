class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>v1(7,0);
        vector<int>v2(7,0);
        vector<int>v3(7,0);
        for(int i=0;i<tops.size();i++)
        {
            v1[tops[i]]++;  
        }
        for(int i=0;i<bottoms.size();i++)
        {
            v2[bottoms[i]]++;  
        }
        int maxi=0;
        int val=0;
        for(int i=0;i<7;i++)
        {
            v3[i] = v1[i]+v2[i];
            if(v3[i]>=maxi)
            {
                maxi = v3[i];
                val = i;
            } 
        }
        if(maxi<tops.size())
        return -1;

        int count1=0;
        for(int i=0;i<tops.size();i++)
        {
            if(tops[i]==val);
            else if(bottoms[i]==val) count1++;
            else return -1;
        }
        int count2=0;
        for(int i=0;i<tops.size();i++)
        {
            if(bottoms[i]==val);
            else if(tops[i]==val) count2++;
            else return -1;
        }
        return min(count1,count2);
    }
};