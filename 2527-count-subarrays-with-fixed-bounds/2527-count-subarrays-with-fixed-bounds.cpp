class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        bool minPresent = false;
        bool maxPresent = false;
        int start = 0;
        int maxi = 0, mini = 0;
        int n = nums.size();
        long long extra = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                minPresent = false;
                maxPresent = false;
                maxi = 0;
                mini = 0;
                extra = 0;
                start = i + 1;
                continue;
            }
            if (nums[i] == minK) {
                minPresent = true;
                mini++;
            }
            if (nums[i] == maxK) {
                maxPresent = true;
                maxi++;
            }
            while (start < i) {
                if (nums[start] == minK && mini > 1) {
                    extra++;
                    start++;
                    mini--;
                } else if (nums[start] == maxK && maxi > 1) {
                    extra++;
                    start++;
                    maxi--;
                } else if(nums[start]!= maxK && nums[start] != minK){
                    start++;
                    extra++;
                }
                else{
                    break;
                }
            }
            if (maxPresent && minPresent) {
                total += 1 + extra;
            }
        }
    return total;
}
}
;