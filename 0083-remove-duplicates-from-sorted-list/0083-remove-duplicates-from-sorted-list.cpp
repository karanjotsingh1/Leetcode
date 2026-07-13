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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            int val=temp->val;
            ListNode* temp1=temp;

            temp=temp->next;
            while(temp!=NULL && temp->val==val)
            {
                temp=temp->next;
            }

            temp1->next=temp;

        }

        return head;
    }
};