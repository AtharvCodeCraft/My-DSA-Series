class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while (second != NULL) {
            if (first->val != second->val) {
                reverse(newHead);      // Restore the list
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverse(newHead);              // Restore the list
        return true;
    }
};