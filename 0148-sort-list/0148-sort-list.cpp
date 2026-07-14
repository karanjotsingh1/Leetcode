// Approach
// 1. Slow te Fast pointers use karke
//    linked list da middle node find karaange.
// 2. Middle ton linked list nu
//    do halves ch split karaange.
// 3. Left half nu recursively sort karaange.
// 4. Right half nu recursively sort karaange.
// 5. Dono sorted halves nu
//    merge karke ik sorted linked list banaavaange.
// 6. Base case:
//    Je linked list empty hove
//    ya sirf ik node hove,
//    ta oh already sorted hai.
// 7. Final merged linked list return karaange.

class Solution
{
public:

    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* list1,ListNode* list2)
    {
        ListNode* dummy=new ListNode(-1);

        ListNode* temp=dummy;

        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
            }

            temp=temp->next;
        }

        if(list1!=NULL)
        {
            temp->next=list1;
        }

        if(list2!=NULL)
        {
            temp->next=list2;
        }

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        // Find middle
        ListNode* middle=findMiddle(head);

        ListNode* secondHalf=middle->next;

        middle->next=NULL;

        // Sort both halves
        ListNode* left=mergeSort(head);

        ListNode* right=mergeSort(secondHalf);

        // Merge sorted halves
        return merge(left,right);
    }

    ListNode* sortList(ListNode* head)
    {
        return mergeSort(head);
    }
};