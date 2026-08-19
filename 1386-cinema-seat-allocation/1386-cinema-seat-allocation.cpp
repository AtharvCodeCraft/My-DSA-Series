class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        
        // Group reserved seats by row using bitwise masks for seats 2 through 9
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            if (col >= 2 && col <= 9) {
                reserved[row] |= (1 << (col - 2));
            }
        }
        
        // Fully empty rows can accommodate up to 2 groups each
        int totalGroups = (n - reserved.size()) * 2;
        
        // Process rows that have reserved seats
        for (const auto& [row, mask] : reserved) {
            bool leftPossible   = (mask & 0b00001111) == 0; // Seats 2, 3, 4, 5
            bool rightPossible  = (mask & 0b11110000) == 0; // Seats 6, 7, 8, 9
            bool middlePossible = (mask & 0b00111100) == 0; // Seats 4, 5, 6, 7
            
            if (leftPossible && rightPossible) {
                totalGroups += 2;
            } else if (leftPossible || rightPossible || middlePossible) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};