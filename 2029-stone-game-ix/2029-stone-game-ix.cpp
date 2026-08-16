class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);
        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        // Case 1: Even number of 0-stones
        if (cnt[0] % 2 == 0) {
            // Alice needs at least one 1-stone and one 2-stone to have a winning path
            return cnt[1] >= 1 && cnt[2] >= 1;
        }

        // Case 2: Odd number of 0-stones
        // Alice wins if the count difference between 1-stones and 2-stones is > 2
        return abs(cnt[1] - cnt[2]) > 2;
    }
};