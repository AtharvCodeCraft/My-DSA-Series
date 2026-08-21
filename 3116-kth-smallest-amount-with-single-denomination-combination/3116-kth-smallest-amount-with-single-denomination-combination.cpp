#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to calculate GCD
    long long gcd(long long a, long long b) {
        return std::gcd(a, b);
    }

    // Helper function to calculate LCM with overflow check
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    // Counts how many amounts <= x can be formed by single denominations
    long long countAmounts(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Iterate through all 2^n - 1 non-empty subsets
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bit_count = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bit_count++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    // If LCM exceeds x, this subset contributes 0
                    if (current_lcm > x) break;
                }
            }

            if (current_lcm <= x) {
                if (bit_count % 2 == 1) {
                    count += x / current_lcm;
                } else {
                    count -= x / current_lcm;
                }
            }
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid amount
            } else {
                low = mid + 1;  // Need a larger amount
            }
        }

        return ans;
    }
};