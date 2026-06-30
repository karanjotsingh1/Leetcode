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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head=new ListNode();
//         ListNode* temp=head;
//         int carry=0;
//         while(l1!=NULL || l2!=NULL || carry){
//             int sum=0;
//             if(l1!=NULL){
//                 sum+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2!=NULL){
//                 sum+=l2->val;
//                 l2=l2->next;
//             }
//             sum+=carry;
//             carry=sum/10;
//             ListNode* newnode=new ListNode(sum%10);
//             temp->next=newnode;
//             temp=temp->next;
//         }
//         return head->next;
//     }
// };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        int carry=0;
        int sum =0;
        while( l1!=NULL || l2!=NULL || carry)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }

            sum+=carry;
            carry=(sum>=10)? 1:0;
            ListNode* next_node=new ListNode(sum%10);
            temp->next=next_node;
            temp=next_node;
            sum=0;
        }
        
        return ans->next;
    }
};