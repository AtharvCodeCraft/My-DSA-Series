class Solution {
public:
    int distinctSubseqII(string s) {
        long last[26] = {0};
        long MOD = 1e9 + 7;

        for (char c : s) {
            long sum_all = 0;
            for (int i = 0; i < 26; ++i) {
                sum_all = (sum_all + last[i]) % MOD;
            }
            // 1 accounts for the single-character subsequence "c"
            last[c - 'a'] = (sum_all + 1) % MOD;
        }

        long total = 0;
        for (int i = 0; i < 26; ++i) {
            total = (total + last[i]) % MOD;
        }

        return total;
    }
};