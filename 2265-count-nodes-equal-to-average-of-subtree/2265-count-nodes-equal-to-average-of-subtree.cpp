class Solution {
public:
    int matchingNodesCount = 0;

    // Helper function returning a pair {subtree_sum, node_count}
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        // Post-order traversal: process left and right children first
        auto [leftSum, leftCount] = dfs(root->left);
        auto [rightSum, rightCount] = dfs(root->right);

        int currentSum = leftSum + rightSum + root->val;
        int currentCount = leftCount + rightCount + 1;

        // Integer division automatically rounds down
        if (currentSum / currentCount == root->val) {
            matchingNodesCount++;
        }

        return {currentSum, currentCount};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodesCount;
    }
};