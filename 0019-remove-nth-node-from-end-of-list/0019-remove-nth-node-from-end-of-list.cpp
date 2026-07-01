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
            
        int total_nodes=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            total_nodes+=1;
            temp=temp->next;
        }
        
        int node_to_reach=total_nodes - n - 1;
        temp=head;

        if(node_to_reach<0)
            return head->next;

        while(node_to_reach!=0)
        {
            temp=temp->next;
            node_to_reach--;
        }
        if(n==1)
            temp->next=NULL;
        else
            temp->next=temp->next->next;

        return head;
    }
};