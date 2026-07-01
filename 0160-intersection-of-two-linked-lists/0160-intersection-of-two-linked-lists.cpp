// Approach
// 1. Pehlaa aapaa dono linked lists di length calculate kraange.
// 2. Hun jis list di length vaddi hougi,
//    usde pointer nu length difference de barabar agge move kraange.
// 3. Is naal dove pointers end ton equal distance te aa jaan ge.
// 4. Hun dove pointers nu ik ik step move kraange.
// 5. Jadon dono pointers same node nu point krange,
//    ohi intersection node hougi.
// 6. Je end takk vi same node na mile,
//    ta NULL return kr devaange.

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
    {
        int len_a=0;
        int len_b=0;

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=NULL)
        {
            len_a++;
            temp1=temp1->next;
        }

        while(temp2!=NULL)
        {
            len_b++;
            temp2=temp2->next;
        }

        temp1=headA;
        temp2=headB;

        int diff=abs(len_a-len_b);

        // Move the pointer of the longer list
        if(len_a>len_b)
        {
            while(diff--)
            {
                temp1=temp1->next;
            }
        }
        else
        {
            while(diff--)
            {
                temp2=temp2->next;
            }
        }

        // Traverse both lists together
        while(temp1!=NULL&&temp2!=NULL)
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