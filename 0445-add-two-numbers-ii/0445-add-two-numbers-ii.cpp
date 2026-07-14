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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* temp=head;

        while(temp)
        {
            ListNode* next_node=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next_node;

        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1=reverse(l1);
        l2=reverse(l2);

        int carry =0;

        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(carry || l1 || l2)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry==1)
            {
                sum+=1;
            }

            if(sum>=10)
            {
                sum=sum%10;
                carry=1;
            }
            else
            {
                carry=0;
            }

            ListNode* new_node=new ListNode(sum);
            temp->next=new_node;
            temp=new_node;
        }

        ans=reverse(ans->next);

        return ans;

    }
};