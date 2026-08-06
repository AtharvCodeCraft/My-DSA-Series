class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp = [](const string& a, const string& b) {
            if (a.length() != b.length()){
                return a.length() > b.length();
            }

            return a > b;
        };

        priority_queue<string, vector<string>, decltype(cmp) > minHeap(cmp);

        for (const string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};