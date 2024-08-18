class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: If the list is empty or has only one node, no swap needed
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Initialize pointers
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* newHead = curr;  // The new head will be the second node after the first swap

        // Loop to swap every pair of nodes
        while (true) {
            // Perform the swap
            prev->next = curr->next;
            curr->next = prev;

            // Prepare for the next swap
            if (prev->next == nullptr || prev->next->next == nullptr) {
                break;  // If no more pairs left, exit the loop
            }

            // Move to the next pair
            ListNode* nextPair = prev->next;
            prev->next = nextPair->next;
            prev = nextPair;
            curr = prev->next;
        }

        return newHead;
    }
};
