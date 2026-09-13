#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> nonZero1, nonZero2;

        // Step 1: Record coordinates of 1s in both images
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) nonZero1.push_back({i, j});
                if (img2[i][j] == 1) nonZero2.push_back({i, j});
            }
        }

        // Map to count frequencies of translation vectors (dr, dc)
        // Encode (dr, dc) into a single key: (dr << 16) | (dc & 0xFFFF)
        unordered_map<int, int> vectorCount;
        int maxOverlap = 0;

        // Step 2 & 3: Compute translation vectors and track max frequency
        for (const auto& p1 : nonZero1) {
            for (const auto& p2 : nonZero2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;
                int key = (dr << 16) | (dc & 0xFFFF);
                
                maxOverlap = max(maxOverlap, ++vectorCount[key]);
            }
        }

        return maxOverlap;
    }
};