// Approach
// 1. Slow te Fast pointers use karke
//    linked list da middle node find karaange.
// 2. Middle ton agge wali linked list
//    reverse karaange.
// 3. Middle node ton list nu
//    do halves ch split karaange.
// 4. Ik pointer first half te
//    ik pointer reversed second half te rakhange.
// 5. Dono halves de nodes nu
//    alternate order ch connect karaange.
// 6. Jadon second half khatam ho jaave,
//    reordered linked list complete ho jaavegi.

class Solution
{
public:

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* current=head;

        while(current!=NULL)
        {
            ListNode* nextNode=current->next;

            current->next=prev;

            prev=current;

            current=nextNode;
        }

        return prev;
    }

    void reorderList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return;
        }

        // Find middle
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalf=reverse(slow->next);

        // Split the list
        slow->next=NULL;

        ListNode* firstHalf=head;

        // Merge alternately
        while(secondHalf!=NULL)
        {
            ListNode* firstNext=firstHalf->next;
            ListNode* secondNext=secondHalf->next;

            firstHalf->next=secondHalf;
            secondHalf->next=firstNext;

            firstHalf=firstNext;
            secondHalf=secondNext;
        }
    }
};