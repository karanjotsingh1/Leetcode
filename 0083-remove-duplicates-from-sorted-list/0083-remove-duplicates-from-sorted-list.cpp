// Approach
// 1. Ik pointer (temp) head ton start karaange.
// 2. Har node lai usdi value store karaange.
// 3. Ik hor pointer (temp1) current node nu point karega.
// 4. Agge traverse karaange
//    jadon tak duplicate values mil diya ne.
// 5. Jadon next different value mil jaave
//    ya list end ho jaave,
//    ta temp1->next nu us different node naal connect kar devaange.
// 6. Is tarah saare duplicate nodes skip ho jaan ge.
// 7. Traversal complete hon to baad
//    modified linked list da head return karaange.

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* temp=head;

        while(temp!=NULL)
        {
            int val=temp->val;

            ListNode* temp1=temp;

            temp=temp->next;

            while(temp!=NULL && temp->val==val)
            {
                temp=temp->next;
            }

            temp1->next=temp;
        }

        return head;
    }
};