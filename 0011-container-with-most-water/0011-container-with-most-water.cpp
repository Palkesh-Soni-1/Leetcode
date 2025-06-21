class Solution {
public:
    int maxArea(vector<int>& height) {

        int l=0;
        int r=height.size()-1;

        int maxi=0;
        
        while(l<r){

            int h1=height[l];
            int h2=height[r];

            int h=min(h1,h2);

            int w=r-l;

            int area=h*w;
              
            maxi=max(maxi,area);

            if(h1<h2){
                l++;
            }else{
                r--;
            } 
        }
        return maxi;
    }
};