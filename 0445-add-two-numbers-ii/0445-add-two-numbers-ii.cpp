// Approach
// 1. Pehla dono linked lists nu reverse karaange,
//    taaki addition least significant digit ton start ho sake.
// 2. Ik carry variable maintain karaange.
// 3. Dono reversed lists nu simultaneously traverse karaange.
// 4. Har step te
//    current digits te carry da sum calculate karaange.
// 5. Sum da last digit
//    answer linked list ch add karaange.
// 6. Je sum 10 ya us ton vadda hove,
//    ta carry = 1,
//    nahi ta carry = 0.
// 7. Eh process jadon tak
//    dono lists te carry khatam na ho jaan,
//    repeat karaange.
// 8. Milia hoya answer reverse order ch hovega,
//    is karke answer linked list nu dubara reverse karaange.
// 9. Final reversed linked list return karaange.

class Solution
{
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* temp=head;

        while(temp!=NULL)
        {
            ListNode* nextNode=temp->next;

            temp->next=prev;

            prev=temp;

            temp=nextNode;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        l1=reverse(l1);
        l2=reverse(l2);

        int carry=0;

        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;

        while(l1!=NULL || l2!=NULL || carry)
        {
            int sum=carry;

            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }

            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }

            carry=sum/10;

            tail->next=new ListNode(sum%10);

            tail=tail->next;
        }

        return reverse(dummy->next);
    }
};