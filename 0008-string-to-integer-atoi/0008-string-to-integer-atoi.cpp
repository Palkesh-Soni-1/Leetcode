class Solution {
public:
    int myAtoi(string s) {
        int length = s.length();
        if(!length)
        return 0;
        int pointer=0;
        while(pointer<length&&s[pointer]==' ')
        pointer++;
        s = s.substr(pointer);
        pointer=0;
        int sign = 1;
        long long ans=0;
        if(s[0]=='-')
        sign = -1;
        if(s[0]=='+'||s[0]=='-')
        pointer++;
        while(pointer<length)
        {
            if(s[pointer]==' '|| (!isdigit(s[pointer])))
            break;
            ans = 10*ans + s[pointer]-'0';
            if(sign==-1 && -1*ans<INT_MIN)
            return INT_MIN;
            if(sign==1 && ans>INT_MAX)
            return INT_MAX;
            pointer++;
        }
        return sign*ans;
    }
};