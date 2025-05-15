class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int prev = -1;
        vector<string> ans;
        for(int i = 0; i<words.size(); i++){
            if(prev != groups[i]) {
                prev = groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};