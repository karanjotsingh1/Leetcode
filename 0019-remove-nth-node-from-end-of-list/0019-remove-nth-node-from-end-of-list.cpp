// Approach
// 1. Ik dummy node banaavaange,
//    jo head ton pehla point karega.
// 2. Do pointers (slow te fast)
//    dummy node ton start karaange.
// 3. Fast pointer nu n+1 steps agge move karaange.
// 4. Hun slow te fast nu
//    ik ik step move karaange.
// 5. Jadon fast NULL ho jaave,
//    slow remove hon wale node ton
//    ik node pehla hovega.
// 6. Slow da next pointer
//    next node wal point kara devaange,
//    jis naal nth node from end remove ho jaavegi.
// 7. Dummy da next hi
//    updated linked list da head hovega.

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head,int n)
    {
        ListNode* dummy=new ListNode(-1);

        dummy->next=head;

        ListNode* slow=dummy;
        ListNode* fast=dummy;

        // Move fast n+1 steps ahead
        for(int i=0;i<=n;i++)
        {
            fast=fast->next;
        }

        // Move both pointers
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }

        // Remove nth node
        slow->next=slow->next->next;

        return dummy->next;
    }
};