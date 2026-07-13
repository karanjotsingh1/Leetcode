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
    ListNode* swapping(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* prev=swapping(head->next->next);

        ListNode* next_node=head->next;
        head->next=prev;
        prev=head;
        next_node->next=head;

        return next_node;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;

        head=swapping(head);
        return head;
    }
};