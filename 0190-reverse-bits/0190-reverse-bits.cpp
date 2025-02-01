class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        string bits = "";
        
        for(int i = 0; i < 32; i++){
            if(n & (1 << i)) bits.push_back('1');
            else bits.push_back('0');
        }
        
        uint32_t ans = 0;
        for(int i = 31, j = 0; i >= 0; i--){
            if(bits[j++] == '1') ans = ans | (1 << i);
        }
        return ans;
        
        //     bool flag=0;
        //     uint32_t ans=0;
        //     int j=0;
        //     for(int i=31;i>=0;i--)
        //     {
        //         int mask = 1<<i;
        //         if(flag)
        //         {
        //             if(n&mask)
        //             {
        //                 int smask = 1<<j;
        //                 ans|=smask;
        //             }
        //             j++;
        //         } else{
        //             if(n&mask)
        //             {
        //                 flag=true;
        //                 int smask = 1<<j;
        //                 ans|=smask;
        //                 j++;
        //             }
        //         }
        //     }
        //     return ans;
        // uint32_t ans=0;
        // for (int i = 0; i <= 31; i++) {
        //     int last = 1<<i;
        //     int value = n&last;
        //     int first = value<<(31-i);
        //     ans = ans | first;
        //     cout<<ans<<endl;
        // }
        // return ans;
    }
};