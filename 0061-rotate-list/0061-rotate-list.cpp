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
        if(head==NULL || head->next==NULL)
            return head;
        
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            count+=1;
        }

        k=k%count;
        if(k==0)
            return head;

        int move_forward=count-k-1;

        temp=head;
        while(move_forward)
        {
            temp=temp->next;
            move_forward--;
        }
        
        ListNode* next_node=temp->next;

        temp->next=NULL;

        temp=next_node;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=head;

        return next_node;
    }
};