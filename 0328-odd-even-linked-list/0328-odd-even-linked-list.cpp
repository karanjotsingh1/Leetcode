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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;

        ListNode* even=new ListNode(-1);
        ListNode*  odd=new ListNode(-1);
        ListNode* temp1=even;
        ListNode* temp2=odd;

        ListNode* temp=head;
        int count=1;

        while(temp)
        {
            if(count%2==0)
            {
                ListNode* new_node=new ListNode(temp->val);
                temp1->next=new_node;
                temp1=new_node;
            }
            else
            {
                ListNode* new_node=new ListNode(temp->val);
                temp2->next=new_node;
                temp2=new_node;
            }

            count+=1;
            temp=temp->next;
        }

        temp2->next=even->next;
        return odd->next;

    }
};