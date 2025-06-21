class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        map<int,int>m1,m2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1;i++)
        {
            m1[nums1[i]]++;
        }
        for(int i=0;i<n2;i++){
            m2[nums2[i]]++;
        }
        for(auto i:m1){
            if(m2.find(i.first)==m2.end()){
                ans[0].push_back(i.first);
            }
        }
        for(auto i:m2){
            if(m1.find(i.first)==m1.end()){
                ans[1].push_back(i.first);
            }
        }
        return ans;
    }
};