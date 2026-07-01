// Approach
// 1. Pehlaa check kraange je list empty aa ya sirf ik node aa,
//    ta sidha head return kr devaange.
// 2. Hun tinn pointers rakhange:
//    prev -> previous node
//    temp -> current node
//    next_node -> next node da address store krn lai.
// 3. Har iteration ch pehlaa next node save kraange,
//    kyunki next pointer change hon to baad list da agla hissa lose ho sakda aa.
// 4. Hun current node da next pointer reverse krke prev wal point kraange.
// 5. Fer prev te temp nu ik step agge move kraange.
// 6. Jadon temp NULL ho jaave,
//    prev hi navi reversed list da head houga.
// 7. Last ch prev return kr devaange.

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }

        ListNode* prev=NULL;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            // Store the next node before breaking the link
            ListNode* next_node=temp->next;

            // Reverse the current link
            temp->next=prev;

            prev=temp;
            temp=next_node;
        }

        return prev;
    }
};