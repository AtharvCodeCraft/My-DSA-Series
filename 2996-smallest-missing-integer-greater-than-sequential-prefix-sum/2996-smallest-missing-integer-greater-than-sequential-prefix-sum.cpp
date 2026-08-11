class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Find the sum of the longest sequential prefix starting at index 0
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Stop as soon as sequential property breaks
            }
        }

        // Step 2: Store all elements of nums in a hash set for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Step 3: Find the smallest integer >= sum that is missing from nums
        while (numSet.count(sum)) {
            sum++;
        }

        return sum;
    }
};