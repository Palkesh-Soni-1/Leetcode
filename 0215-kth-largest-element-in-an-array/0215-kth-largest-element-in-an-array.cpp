class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> min_heap(nums.begin(), nums.begin() + k);
        
        // for (int i = k; i < nums.size(); i++) {
        //     if (nums[i] > min_heap.top()) {
        //         min_heap.pop();
        //         min_heap.push(nums[i]);
        //     }
        // }

        priority_queue<int, vector<int>, greater<int>> mini;
        for(int i=0;i<nums.size();i++)
        {
            mini.push(nums[i]);
            if(mini.size()>k)
            {
                mini.pop();
            }
        }
        // return min_heap.top();
        return mini.top();
    }
};