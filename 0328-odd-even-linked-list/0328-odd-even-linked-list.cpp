// Approach
// 1. Ik odd pointer te
//    ik even pointer maintain karaange.
// 2. Even list da head
//    alag store karaange,
//    taaki baad ch connect kar sakiye.
// 3. Odd pointer nu
//    agle odd node naal connect karaange.
// 4. Even pointer nu
//    agle even node naal connect karaange.
// 5. Har iteration ch
//    odd te even pointers nu
//    agge move karaange.
// 6. Jadon even list khatam ho jaave,
//    ta odd list de end nu
//    even list de head naal connect karaange.
// 7. Original head hi
//    required answer hovega.

class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* odd=head;

        ListNode* even=head->next;

        ListNode* evenHead=even;

        while(even!=NULL && even->next!=NULL)
        {
            odd->next=even->next;

            odd=odd->next;

            even->next=odd->next;

            even=even->next;
        }

        odd->next=evenHead;

        return head;
    }
};