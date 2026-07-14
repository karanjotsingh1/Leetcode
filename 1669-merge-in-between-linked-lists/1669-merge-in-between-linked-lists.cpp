// Approach
// 1. List1 ch
//    index a ton pehla wala node find karaange.
// 2. List1 ch
//    index b ton baad wala node find karaange.
// 3. Previous node da next
//    list2 de head naal connect karaange.
// 4. List2 de last node tak traverse karaange.
// 5. List2 de last node nu
//    b ton baad wale node naal connect karaange.
// 6. Modified list1 da head return karaange.

class Solution
{
public:
    ListNode* mergeInBetween(ListNode* list1,int a,int b,ListNode* list2)
    {
        // Node before index 'a'
        ListNode* prevA=list1;

        if(a==0)
        {
            prevA=NULL;
        }
        else
        {
            for(int i=1;i<a;i++)
            {
                prevA=prevA->next;
            }
        }

        // Node after index 'b'
        ListNode* afterB=list1;

        for(int i=0;i<=b;i++)
        {
            afterB=afterB->next;
        }

        // Find tail of list2
        ListNode* tail=list2;

        while(tail->next!=NULL)
        {
            tail=tail->next;
        }

        // If head is removed
        if(prevA==NULL)
        {
            tail->next=afterB;

            return list2;
        }

        // Connect list1 with list2
        prevA->next=list2;

        // Connect tail of list2 with remaining list1
        tail->next=afterB;

        return list1;
    }
};