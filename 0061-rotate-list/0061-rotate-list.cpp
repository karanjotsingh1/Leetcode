// Approach
// 1. Pehlaa check kraange je list empty aa ya sirf ik node aa,
//    ta rotation di lod nhi, head return kr devaange.
// 2. Hun linked list di length calculate kraange.
// 3. K nu length naal modulo kr devaange,
//    kyunki len rotations to baad list dubara same ho jaandi aa.
// 4. Je k 0 ban jaave,
//    ta head hi return kr devaange.
// 5. Hun nava tail labhaange jo (len-k-1)th node houga.
// 6. Nava head, nava tail de agle node ton start houga.
// 7. Old tail nu head naal connect kraange,
//    te nava tail da next NULL kr devaange.
// 8. Last ch nava head return kr devaange.

/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x,ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* rotateRight(ListNode* head,int k)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }

        int len=1;
        ListNode* tail=head;

        // Find length and last node
        while(tail->next!=NULL)
        {
            tail=tail->next;
            len++;
        }

        k%=len;

        if(k==0)
        {
            return head;
        }

        int node_to_move=len-k-1;
        ListNode* temp=head;

        // Find the new tail
        while(node_to_move--)
        {
            temp=temp->next;
        }

        ListNode* new_head=temp->next;

        // Make the list circular and then break it
        tail->next=head;
        temp->next=NULL;

        return new_head;
    }
};