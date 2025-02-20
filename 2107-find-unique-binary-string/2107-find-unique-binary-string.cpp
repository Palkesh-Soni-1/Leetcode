class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        //store all existing number in ans array
        vector<int>ans;
        //size of num = n
        int n = nums.size();

        //storing
        for(int i=0;i<nums.size();i++)
        {
            string s = nums[i];
            int x = n-1;
            int num=0;
            for(int j=0;j<n;j++)
            {
                int y = int(s[j]-'0');
                num+=(pow(2,x)*y);
                x--;
            }
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());

        //check ans array
        // for(int i=0;i<n;i++)
        // {
        //     cout<<ans[i]<<endl;
        // }

        //find number that doesn't appear
        int number=n;
        for(int i=0;i<n;i++)
        {
            if(i!=ans[i])
            {
                number=i;
                break;
            }
        }
        cout<<"number-: "<<number<<endl;
        
        //convert number to string
        string numb="";
        while(number>0)
        {
            // cout<<number%2<<endl;
            string rem = to_string(number%2);
            cout<<rem<<endl;
            numb+=rem;
            number/=2; 
        }
        //reverse numb
        reverse(numb.begin(),numb.end());
        // cout<<"numb-: "<<numb<<endl;

        int difflength = n-numb.length();
        // cout<<"difflength-: "<<difflength<<endl;

        string dummy="";
        for(int i=0;i<difflength;i++)
        dummy+="0";
        // cout<<dummy<<endl;
        
        string final = dummy+numb;
        return final;
    }
};