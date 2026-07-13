// Approach
// 1. Tin pointers use karaange:
//    prev, temp te next_node.
// 2. Prev nu NULL initialize karaange,
//    kyunki reversed list da last node
//    NULL nu point karega.
// 3. Temp head ton traversal start karega.
// 4. Current node de next pointer nu
//    temporary variable (next_node) ch store karaange.
// 5. Current node da next
//    previous node wal point kara devaange.
// 6. Prev nu current node te move karaange.
// 7. Temp nu next_node te move karaange.
// 8. Eh process jadon tak
//    temp NULL na ho jaave,
//    repeat karaange.
// 9. Traversal complete hon to baad
//    prev hi reversed linked list da new head hovega.

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp!=NULL)
        {
            ListNode* next_node=temp->next;

            temp->next=prev;

            prev=temp;

            temp=next_node;
        }

        return prev;
    }
};