class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        
        // Find the maximum element in piles without using std::max_element
        int right = piles[0];
        for (int i = 1; i < piles.size(); ++i) {
            if (piles[i] > right) {
                right = piles[i];
            }
        }

        int ans = right;

        // Binary search for minimum eating speed k
        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;
            for (int i = 0; i < piles.size(); ++i) {
                // Ceiling division: ceil(piles[i] / mid)
                hours += (piles[i] + mid - 1LL) / mid;
            }

            if (hours <= h) {
                ans = mid;       // Try to find a smaller valid speed
                right = mid - 1;
            } else {
                left = mid + 1;  // Speed is too slow, increase speed
            }
        }

        return ans;
    }
};