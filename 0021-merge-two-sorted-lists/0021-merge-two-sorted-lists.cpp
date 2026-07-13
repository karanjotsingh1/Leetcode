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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode(-1);

        ListNode* temp=head;
        ListNode* temp1=list1;
        ListNode* temp2=list2;

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->val == temp2->val)
            {
                ListNode* new_node1=new ListNode(temp1->val);
                ListNode* new_node2=new ListNode(temp2->val);

                temp->next=new_node1;
                temp=temp->next;

                temp->next=new_node2;
                temp=temp->next;

                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->val < temp2->val)
            {
                ListNode* new_node1=new ListNode(temp1->val);
                temp->next=new_node1;
                temp=temp->next;

                temp1=temp1->next;
            }
            else
            {
                ListNode* new_node2=new ListNode(temp2->val);
                temp->next=new_node2;
                temp=temp->next;

                temp2=temp2->next;
            }
        }

        if(temp1!=NULL)
        {
            temp->next=temp1;
        }
        if(temp2!=NULL)
        {
            temp->next=temp2;
        }

        return head->next;

    }
};