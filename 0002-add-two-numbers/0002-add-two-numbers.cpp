// Approach
// 1. Pehlaa aapaa ik dummy node(ans) bnaavaange taaki answer list easily build ho sake.
// 2. Ik temp pointer rakhange jo hamesha answer list de last node nu point kru ga.
// 3. Ik carry variable rakhange jo previous addition da carry store kru ga.
// 4. Hun jadon takk l1, l2 ya carry exist krde ne,
//    ona nu ik ik karke add kraange.
// 5. Sum da last digit navi node bna ke answer list ch add kr devaange,
//    te carry update kr devaange.
// 6. Jadon saari nodes process ho jaan,
//    dummy node de next nu return kr devaange.

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        int carry=0;
        int sum=0;

        while(l1!=NULL||l2!=NULL||carry)
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
            carry=sum/10;

            // Create a node for the current digit
            ListNode* next_node=new ListNode(sum%10);
            temp->next=next_node;
            temp=next_node;

            sum=0;
        }

        return ans->next;
    }
};