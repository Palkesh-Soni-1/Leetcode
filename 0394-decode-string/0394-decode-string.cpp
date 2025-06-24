class Solution {

    bool isDigit(char c)
    {
        if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
        return true;
        return false;
    }
public:
    string decodeString(string s) {
        int n =s.length();
        stack<char>st;
        string ans="";
        string temp="";
        for(int i=0;i<n;i++)
        {
            // if(st.empty())
            // {
            //     ans+=temp;
            //     temp="";
            // }
            if(s[i]==']')
            {
                string temp1="";
                while(!st.empty())
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                        int x = 1;
                        int range=0;
                        string number = "";
                        while(!st.empty() && isDigit(st.top()))
                        {
                            number=st.top()+number;
                            // int d = st.top();
                            // cout<<d<<endl;
                            // range+=(x*d);
                            // x*=10;
                            st.pop();
                        }
                        range = stoi(number);
                        // cout<<range<<endl;
                        string temp2="";
                        reverse(temp1.begin(),temp1.end());
                        for(int i=0;i<range;i++)
                        {
                            temp2+=temp1;
                        }
                        // cout<<temp2.length()<<endl;
                        // cout<<temp2<<endl;
                        for(int i=0;i<temp2.length();i++)
                        {
                            st.push(temp2[i]);
                        }
                        break;
                    }
                    else{
                        temp1.push_back(st.top());
                        st.pop();
                    }
                }
            }
            else{
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};