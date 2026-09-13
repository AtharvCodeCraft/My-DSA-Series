#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int valid_count = 0;

        // All 3-digit even numbers start at 100 and end at 998
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;        // Hundreds digit
            int d2 = (num / 10) % 10;  // Tens digit
            int d3 = num % 10;         // Units digit

            std::vector<int> req(10, 0);
            req[d1]++;
            req[d2]++;
            req[d3]++;

            // Check if available digit frequencies satisfy the required counts
            bool possible = true;
            for (int d = 0; d < 10; ++d) {
                if (req[d] > count[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                valid_count++;
            }
        }

        return valid_count;
    }
};