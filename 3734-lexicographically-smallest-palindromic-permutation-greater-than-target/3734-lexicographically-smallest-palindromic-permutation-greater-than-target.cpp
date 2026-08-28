#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_cnt = 0;
        int mid_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_cnt++;
                mid_char = i;
            }
        }

        // Return empty string if palindrome permutation is impossible
        if ((n % 2 == 0 && odd_cnt > 0) || (n % 2 != 0 && odd_cnt != 1)) {
            return "";
        }

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int m = n / 2;
        string best_ans = "";

        // Helper lambda to construct full palindrome from left half
        auto build_palindrome = [&](const string& left_half) {
            string res = left_half;
            if (n % 2 != 0) {
                res += (char)('a' + mid_char);
            }
            string right_half = left_half;
            reverse(right_half.begin(), right_half.end());
            res += right_half;
            return res;
        };

        // Step 1: Check if target's first half can be exactly matched
        vector<int> cur_half = half_count;
        bool can_match_exact = true;
        for (int i = 0; i < m; ++i) {
            int ch = target[i] - 'a';
            if (cur_half[ch] > 0) {
                cur_half[ch]--;
            } else {
                can_match_exact = false;
                break;
            }
        }

        if (can_match_exact) {
            string candidate = build_palindrome(target.substr(0, m));
            if (candidate > target) {
                best_ans = candidate;
            }
        }

        // Step 2: Find largest prefix of length L where target[L] can be replaced with c > target[L]
        // Re-calculate how far target's prefix can be matched
        cur_half = half_count;
        int max_L = 0;
        while (max_L < m && cur_half[target[max_L] - 'a'] > 0) {
            cur_half[target[max_L] - 'a']--;
            max_L++;
        }

        // Try prefix lengths L from max_L down to 0
        for (int L = max_L; L >= 0; --L) {
            int start_char = target[L] - 'a' + 1;
            
            // Look for smallest available char > target[L]
            int next_char = -1;
            for (int ch = start_char; ch < 26; ++ch) {
                if (cur_half[ch] > 0) {
                    next_char = ch;
                    break;
                }
            }

            if (next_char != -1) {
                // Form left half: prefix of target + next_char + remaining chars in sorted order
                string left_half = target.substr(0, L);
                left_half += (char)('a' + next_char);
                cur_half[next_char]--;

                for (int ch = 0; ch < 26; ++ch) {
                    while (cur_half[ch] > 0) {
                        left_half += (char)('a' + ch);
                        cur_half[ch]--;
                    }
                }

                string candidate = build_palindrome(left_half);
                if (best_ans.empty() || candidate < best_ans) {
                    best_ans = candidate;
                }
                break; // Found the lexicographically optimal prefix length
            }

            // Backtrack: restore target[L - 1] to available counts for the next loop iteration
            if (L > 0) {
                cur_half[target[L - 1] - 'a']++;
            }
        }

        return best_ans;
    }
};