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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;

        if(temp == NULL || temp->next == NULL)
        return head;

        int p;
        p = temp->val;
        temp->val = temp->next->val;
        temp->next->val = p;

        // recursive approach
        if(temp->next->next != NULL)
        {
            temp->next->next = swapPairs(temp->next->next);
        }

        return head;
        
    }
};