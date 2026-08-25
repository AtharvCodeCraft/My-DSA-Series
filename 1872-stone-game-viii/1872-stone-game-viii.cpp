class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums
        vector<long long> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }
        
        // Base case: taking all stones leaves no future moves
        long long max_diff = pref[n - 1];
        
        // Transition backward from index n-2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            max_diff = max(max_diff, pref[i] - max_diff);
        }
        
        return max_diff;
    }
};