class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v;
        int size=n/2;
        int num1=1;int num2=-1;
        for(int i=1;i<=size;i++){
           v.push_back(num1);
           v.push_back(num2);
           num1++;num2--;
        }
        if(n%2) v.push_back(0);
        return v;
    }
};