#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

// Worst time complexity -> nlogn if k = n
class Solution {
public:

    int findKthLargest(std::vector<int>& nums, int k) {
        // Create max heap
        make_heap(nums.begin(), nums.end()); // log(n)

        int answer = 0;
        for (int i=1; i<=k; i++) {
            pop_heap(nums.begin(), nums.end()); // log(n) - moves max value to back of vector and remakes the heap
            answer = nums.back();
            nums.pop_back();
        }

        return answer;
    }
};