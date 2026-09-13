#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // Form tuples of {left, right, weight, original_index}
        vector<vector<long long>> items(n);
        for (int i = 0; i < n; ++i) {
            items[i] = {(long long)intervals[i][0], (long long)intervals[i][1], (long long)intervals[i][2], (long long)i};
        }
        
        // Sort intervals by left endpoint (start position)
        sort(items.begin(), items.end(), [](const vector<long long>& a, const vector<long long>& b) {
            return a[0] < b[0];
        });
        
        // Extract start times to perform binary search
        vector<long long> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = items[i][0];
        }
        
        // dp[i][k] = optimal {max_weight, lexicographically smallest list of indices}
        // considering intervals from index i to n-1, choosing at most k intervals.
        using DPState = pair<long long, vector<int>>;
        vector<vector<DPState>> dp(n + 1, vector<DPState>(5, {0, {}}));
        
        for (int i = n - 1; i >= 0; --i) {
            long long l = items[i][0];
            long long r = items[i][1];
            long long wt = items[i][2];
            int orig_idx = (int)items[i][3];
            
            // Find the first interval starting strictly after current interval's right endpoint
            int next_idx = upper_bound(starts.begin(), starts.end(), r) - starts.begin();
            
            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip current interval
                DPState best = dp[i + 1][k];
                
                // Option 2: Include current interval
                long long take_weight = wt + dp[next_idx][k - 1].first;
                vector<int> take_indices;
                take_indices.reserve(1 + dp[next_idx][k - 1].second.size());
                take_indices.push_back(orig_idx);
                take_indices.insert(take_indices.end(), dp[next_idx][k - 1].second.begin(), dp[next_idx][k - 1].second.end());
                sort(take_indices.begin(), take_indices.end()); // Keep indices sorted for strict lexicographical format
                
                DPState take = {take_weight, take_indices};
                
                // Select the option with larger weight, or lexicographically smaller indices on tie
                if (take.first > best.first) {
                    best = take;
                } else if (take.first == best.first && take.first > 0) {
                    if (best.first == 0 || take.second < best.second) {
                        best = take;
                    }
                }
                
                dp[i][k] = best;
            }
        }
        
        return dp[0][4].second;
    }
};