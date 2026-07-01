// Approach
// 1. Pehlaa aapaa poori linked list traverse krke total nodes count kraange.
// 2. Hun start ton oh node labhaange jo delete hon wale node ton ik position pehlaa hove.
// 3. Je head hi delete hona hove,
//    ta head->next return kr devaange.
// 4. Nahi ta previous node da next,
//    delete hon wale node de next wal point krwa devaange.
// 5. Last ch updated head return kr devaange.

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head,int n)
    {
        int total_nodes=0;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            total_nodes++;
            temp=temp->next;
        }

        int node_to_reach=total_nodes-n-1;

        if(node_to_reach<0)
        {
            return head->next;
        }

        temp=head;

        while(node_to_reach>0)
        {
            temp=temp->next;
            node_to_reach--;
        }

        // Remove the required node
        temp->next=temp->next->next;

        return head;
    }
};