

class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_count;

        // Iterate through all contiguous subarrays of size k
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_elements;
            for (int j = i; j < i + k; ++j) {
                unique_elements.insert(nums[j]);
            }
            for (int val : unique_elements) {
                subarray_count[val]++;
            }
        }

        int ans = -1;
        // Find the largest element that appears in exactly 1 subarray of size k
        for (auto& [val, count] : subarray_count) {
            if (count == 1) {
                ans = max(ans, val);
            }
        }

        return ans;
    }
};