class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        int minVal = nums1[0];

        for (int x : nums1) {
            if ( x % 2!= 0) {
                hasOdd = true;
            }

            if ( x < minVal) {
                minVal = x;
            }
        }

        return !hasOdd || (minVal % 2 != 0);
    }
};