class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        for (int num :  arr1) {
            freq[num]++;
        }

        vector<int> result;
        for (int num : arr2) {
            while (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }
            vector<int> remaining;
            for (auto & [num, count] : freq) {
                while (count > 0) {
                    remaining.push_back(num);
                    count--;
                }
            }

            sort(remaining.begin(), remaining.end());
            for (int num : remaining) {
                result.push_back(num);
            }

        return result;
    }

    
};