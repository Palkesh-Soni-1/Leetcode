class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        int n = asteroids.size();
        stack<int>s1,s2;
        for(int i=n-1;i>=0;i--)
        {
            if(s1.empty()&&asteroids[i]>0)
            s2.push(asteroids[i]);
            else{
                if(asteroids[i]<0)
                s1.push(asteroids[i]);
                else{
                    int a = asteroids[i];
                    int flag=0;
                    while(!s1.empty())
                    {
                        if(a>abs(s1.top()))
                        s1.pop();
                        else if(a==abs(s1.top()))
                        {
                            s1.pop();
                            flag=1;
                            break;
                        }
                        else{
                            break;
                        }
                    }
                    if(!flag&&s1.empty())
                    s2.push(a);
                }
            }
        }

        while(!s1.empty())
        {
            ans.emplace_back(s1.top());
            s1.pop();
        }
        while(!s2.empty())
        {
            ans.emplace_back(s2.top());
            s2.pop();
        }
        // reverse(ans.begin(), ans.end());
        return ans;
        
    }
};