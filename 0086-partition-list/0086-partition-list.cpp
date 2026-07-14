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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
            return head;
            
        ListNode* first=new ListNode(-1);
        ListNode* last=new ListNode(-1);

        ListNode* temp=head;
        ListNode* temp1=first;
        ListNode* temp2=last;

        while(temp)
        {
            if(temp->val >=x)
            {
                ListNode* new_node=new ListNode(temp->val);
                temp2->next=new_node;
                temp2=new_node;
            }
            else
            {
                ListNode* new_node=new ListNode(temp->val);
                temp1->next=new_node;
                temp1=new_node;
            }
            temp=temp->next;
        }


        temp1->next=last->next;

        return first->next;

    }
};