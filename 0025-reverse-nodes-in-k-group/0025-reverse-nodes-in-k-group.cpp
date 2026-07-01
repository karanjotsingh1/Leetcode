// Approach
// 1. Pehlaa check kraange ki current group ch k nodes present ne ya nahi.
//    Je k nodes nhi ne, ta current node hi return kr devaange,
//    kyunki last incomplete group nu reverse nhi krna.
// 2. Je k nodes present ne,
//    ta remaining list lai recursively function call kraange.
// 3. Recursive call sanu agle groups da reversed head return kru gi.
// 4. Hun current k nodes nu reverse kraange
//    te ona da last node recursively returned list naal connect kr devaange.
// 5. Reverse complete hon to baad current group da nava head return kr devaange.
// 6. Is process naal saare complete groups reverse ho jaan ge,
//    te last incomplete group unchanged hi reh jaega.

class Solution
{
public:
    ListNode* get_head(ListNode* node,int k)
    {
        ListNode* temp=node;
        int cnt=0;

        // Check if current group has k nodes
        while(cnt<k&&temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }

        if(cnt<k)
        {
            return node;
        }

        // Reverse the remaining groups first
        ListNode* prev=get_head(temp,k);

        // Reverse current group
        while(cnt--)
        {
            ListNode* next_node=node->next;
            node->next=prev;
            prev=node;
            node=next_node;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head,int k)
    {
        if(head==NULL)
        {
            return NULL;
        }

        return get_head(head,k);
    }
};