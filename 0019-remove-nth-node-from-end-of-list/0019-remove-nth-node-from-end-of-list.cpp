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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;

        while(temp)
        {
            count+=1;
            temp=temp->next;
        }

        if(n==count)
            return head->next;

        int move_forward=count-n-1;

        temp=head;
        while(move_forward)
        {
            temp=temp->next;
            move_forward--;
        }

        if(n==1)
        {
            temp->next=NULL;
            return head;
        }
        else
        {
            temp->next=temp->next->next;
            return head;
        }
        
    }
};