// Approach
// 1. Ik dummy node banaavaange,
//    jo head ton pehla point karega.
// 2. Ik pointer (temp) dummy ton start karaange.
// 3. Jadon temp->next exist kare,
//    current next node check karaange.
// 4. Je next node di value
//    given value de equal hove,
//    ta us node nu skip kar devaange
//    by changing temp->next.
// 5. Je value equal na hove,
//    ta temp nu agge move karaange.
// 6. Traversal complete hon to baad
//    dummy->next hi updated linked list da head hovega.

class Solution
{
public:
    ListNode* removeElements(ListNode* head,int val)
    {
        ListNode* dummy=new ListNode(-1);

        dummy->next=head;

        ListNode* temp=dummy;

        while(temp->next!=NULL)
        {
            if(temp->next->val==val)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
        }

        return dummy->next;
    }
};