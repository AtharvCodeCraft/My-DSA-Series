class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Take current element (can be reused)
        curr.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index);
        curr.pop_back();

        // Skip current element
        solve(candidates, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};