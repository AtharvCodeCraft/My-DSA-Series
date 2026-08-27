#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Try to match target[0...i-1] exactly, and at index i choose a character > target[i]
        // We want to find the largest possible prefix match (rightmost divergence point i)
        
        // First, check how far we can match target strictly equal
        vector<int> temp_count = count;
        int matched = 0;
        while (matched < n && temp_count[target[matched] - 'a'] > 0) {
            temp_count[target[matched] - 'a']--;
            matched++;
        }

        // Backtrack from the maximum possible match length down to 0
        for (int i = matched; i >= 0; i--) {
            // Restore character counts up to index i
            vector<int> current_count = count;
            for (int k = 0; k < i; k++) {
                current_count[target[k] - 'a']--;
            }

            // At index i, try picking the smallest character strictly greater than target[i]
            // Note: If i == n, target is fully matched, which is equal (not strictly greater).
            if (i < n) {
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (current_count[c] > 0) {
                        // Found valid character at position i
                        current_count[c]--;

                        string result = target.substr(0, i);
                        result += (char)('a' + c);

                        // Fill the rest in ascending order
                        for (int ch = 0; ch < 26; ch++) {
                            while (current_count[ch] > 0) {
                                result += (char)('a' + ch);
                                current_count[ch]--;
                            }
                        }
                        return result;
                    }
                }
            }
        }

        return "";
    }
};