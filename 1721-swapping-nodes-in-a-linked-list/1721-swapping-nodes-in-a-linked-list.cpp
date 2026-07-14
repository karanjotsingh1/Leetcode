// Approach
// 1. Pehla linked list di length calculate karaange.
// 2. Beginning ton kth node find karaange.
// 3. End ton kth node find karaange.
// 4. Dono nodes di values swap karaange.
// 5. Original head return karaange.

class Solution
{
public:
    ListNode* swapNodes(ListNode* head,int k)
    {
        int length=0;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            length++;

            temp=temp->next;
        }

        ListNode* firstNode=head;

        for(int i=1;i<k;i++)
        {
            firstNode=firstNode->next;
        }

        ListNode* secondNode=head;

        for(int i=1;i<=(length-k);i++)
        {
            secondNode=secondNode->next;
        }

        swap(firstNode->val,secondNode->val);

        return head;
    }
};