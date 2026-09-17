#include <vector>
#include <algorithm>

class Solution {
public:
    int minSumOfLengths(std::vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a sub-array with sum == target ending at or before index i
        std::vector<int> min_len(n, INT_MAX);
        
        int left = 0;
        int current_sum = 0;
        int min_window = INT_MAX;
        int ans = INT_MAX;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            // Shrink window if current_sum exceeds target
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }

            // Valid sub-array found
            if (current_sum == target) {
                int current_len = right - left + 1;

                // Check if a valid non-overlapping sub-array exists to the left
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = std::min(ans, current_len + min_len[left - 1]);
                }

                // Update best length seen so far up to current index
                min_window = std::min(min_window, current_len);
            }

            // Carry over the minimum length seen so far
            min_len[right] = min_window;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};