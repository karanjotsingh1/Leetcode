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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL)
            return head;
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len+=1;
            temp=temp->next;
        }

        k=k%len;
        if(k==0)
            return head;   
             
        int node_to_move= len-k-1;

        temp=head;
        while(node_to_move--)
        {
            temp=temp->next;
        }
        ListNode* next_node=temp->next;
        temp->next=NULL;
        ListNode* temp1=next_node;
        while(temp1->next)
        {
            temp1=temp1->next;
        }
        temp1->next=head;
        return next_node;
    }
};