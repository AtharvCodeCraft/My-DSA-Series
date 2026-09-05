class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1; // 1 way to make amount 0

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};