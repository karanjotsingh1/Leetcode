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

        ListNode* temp1=head;

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        while(temp1)
        {
            int ele=temp1->val;
            int count=0;
            while(temp1->next && temp1->next->val==ele)
            {
                count+=1;
                temp1=temp1->next;
            }
            if(count==0)
            {
                ListNode* new_node=new ListNode(temp1->val);
                temp->next=new_node;
                temp=temp->next;
            }
            temp1=temp1->next;
        }
        
        return ans->next;
    }
};