#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;

        while (pq.top() < k && pq.size() > 1) {
            long long smallest = pq.top(); pq.pop();
            long long second_smallest = pq.top(); pq.pop();

            long long new_element = smallest + 2 * second_smallest; // Safely using long long
            pq.push(new_element);
            count++;
        }

        return count;
    }
};
