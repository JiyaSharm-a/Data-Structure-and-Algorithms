/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        //delete(node->next);
        //node->next = NULL;
        if(node->next->next != NULL)
        {
            node->next = node->next->next;
        }
        else
        node->next = NULL;
    }
};