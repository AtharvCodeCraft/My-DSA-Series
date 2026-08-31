/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;
        
        int firstCriticalIdx = -1;
        int prevCriticalIdx = -1;
        int minDistance = INT_MAX;

        while (curr->next) {
            // Check if current node is local maxima or local minima
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstCriticalIdx == -1) {
                    firstCriticalIdx = index;
                } else {
                    minDistance = min(minDistance, index - prevCriticalIdx);
                }
                
                prevCriticalIdx = index;
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }

        // If less than 2 critical points are found
        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = prevCriticalIdx - firstCriticalIdx;
        return {minDistance, maxDistance};
    }
};