// Approach
// 1. Pehla dono linked lists di length calculate karaange.
// 2. Length da difference (diff) find karaange.
// 3. Jis linked list di length zyada hove,
//    usde pointer nu diff nodes agge move karaange,
//    taaki dono pointers de kol
//    equal number of nodes bach jaan.
// 4. Hun dono pointers nu
//    ik ik step move karaange.
// 5. Je dono pointers kise vi node te equal ho jaan,
//    matlab intersection node mil gayi.
//    Us node nu return karaange.
// 6. Je traversal complete ho jaave
//    te pointers kabhi equal na hon,
//    ta intersection exist nahi karda.
// 7. Is case ch NULL return karaange.

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA,ListNode *headB)
    {
        int count1=0;
        int count2=0;

        ListNode* temp1=headA;
        while(temp1!=NULL)
        {
            count1++;
            temp1=temp1->next;
        }

        ListNode* temp2=headB;
        while(temp2!=NULL)
        {
            count2++;
            temp2=temp2->next;
        }

        temp1=headA;
        temp2=headB;

        if(count1>count2)
        {
            int diff=count1-count2;

            while(diff--)
            {
                temp1=temp1->next;
            }
        }
        else if(count2>count1)
        {
            int diff=count2-count1;

            while(diff--)
            {
                temp2=temp2->next;
            }
        }

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2)
            {
                return temp1;
            }

            temp1=temp1->next;
            temp2=temp2->next;
        }

        return NULL;
    }
};