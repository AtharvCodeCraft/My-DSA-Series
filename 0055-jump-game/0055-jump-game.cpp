class Solution {
public:
    bool canJump(vector<int>& arr) {
        int maxFind = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i > maxFind)
            return false;

            maxFind = max(maxFind, i + arr[i]);
        }

        return true;
    }
};