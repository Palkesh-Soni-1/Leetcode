class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        // if(n==1)
        // return true;
        // else{
            int one=0;
            for(int i=0;i<n;i++)
            {
                if(derived[i]==1)
                one++;
            }
            if(one%2)
            return false;
            else
            return true;
    //     }
    }
};