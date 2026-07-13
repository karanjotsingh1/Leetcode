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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=NULL;
        while(slow!=NULL)
        {
            ListNode* next_node=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next_node;
        }

        fast=head;
        while(fast!=NULL && prev!=NULL)
        {
            if(fast->val!=prev->val)
                return false;

            prev=prev->next;
            fast=fast->next;
        }
        return true;
    }
};