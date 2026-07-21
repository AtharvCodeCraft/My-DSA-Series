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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        
        // Pass 1: Count the total number of nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        // Calculate the middle position
        int midNode = (count / 2) + 1;
        temp = head;
        
        // Pass 2: Move temp to the middle node position
        while (temp != NULL) {
            midNode = midNode - 1;
            if (midNode == 0) {
                break;
            }
            temp = temp->next;
        }
        
        return temp; 
    }
};
