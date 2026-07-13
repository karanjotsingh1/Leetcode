// Approach
// 1. Ik dummy node banaavaange,
//    jo merged list da starting point hovega.
// 2. Ik pointer (temp) maintain karaange,
//    jo merged list da last node represent karega.
// 3. Dono linked lists nu simultaneously traverse karaange.
// 4. Je list1 da current node chhota ya equal hove,
//    ta us node nu merged list ch attach karaange
//    te list1 nu agge move karaange.
// 5. Nahi ta list2 da current node attach karaange
//    te list2 nu agge move karaange.
// 6. Har attachment ton baad
//    temp nu agge move karaange.
// 7. Jadon kise ik list de nodes khatam ho jaan,
//    ta doosri list de saare remaining nodes
//    directly merged list ch attach kar devaange.
// 8. Dummy node de next nu return karaange,
//    jo merged sorted list da head hovega.

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
    {
        ListNode* head=new ListNode(-1);

        ListNode* temp=head;

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

        return head->next;
    }
};