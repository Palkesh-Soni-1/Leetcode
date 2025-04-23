class Solution {
public:
   int helper(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
   }
    int countLargestGroup(int n) {
       unordered_map<int,int>m;
       int maxi=0;
       while(n){
        int digit=helper(n);
        m[digit]++;
        maxi=max(maxi,m[digit]);
        n--;
       }
       int cnt=0;
       for(auto ele:m){
        if(ele.second==maxi)cnt++;
       }
       return cnt;
    }
};