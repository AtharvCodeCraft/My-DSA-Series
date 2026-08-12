#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Add current element to frequency map
            freq[nums[right]]++;

            // Shrink window from the left if any element frequency exceeds k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            // Update maximum length of valid subarray
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};