class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        ListNode* first = head;
        ListNode* second = secondHalf;
        bool isPalindrome = true;

        while (second) {
            if (first->val != second->val) {
                isPalindrome = false;
                break;
            }
            first = first->next;
            second = second->next;
        }

        slow->next = reverseList(secondHalf);
        return isPalindrome;
    }
};