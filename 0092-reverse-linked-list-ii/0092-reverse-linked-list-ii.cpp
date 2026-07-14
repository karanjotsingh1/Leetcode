// Approach
// 1. Je left te right same hon
//    ya linked list empty hove,
//    ta original head return karaange.
// 2. Je left == 1 hove,
//    ta first right nodes reverse karaange.
// 3. Reversed part de next nu
//    remaining linked list naal connect karaange.
// 4. Je left > 1 hove,
//    ta pehla left-1 position tak move karaange,
//    taaki reversed part ton pehla wala node mil jaave.
// 5. Right position ton agla node
//    (last part da first node) find karaange.
// 6. Left te Right de vichale saare nodes reverse karaange,
//    te reversed part da last node
//    last part naal connect karaange.
// 7. First part de last node nu
//    reversed part de first node naal connect karaange.
// 8. Final modified linked list da head return karaange.

class Solution
{
public:
    ListNode* reverseBetween(ListNode* head,int left,int right)
    {
        if(head==NULL || head->next==NULL || left==right)
        {
            return head;
        }

        // Case 1 : Reverse starts from head
        if(left==1)
        {
            int nodesToReverse=right;

            ListNode* current=head;
            ListNode* nextPartHead=head;

            while(right--)
            {
                nextPartHead=nextPartHead->next;
            }

            ListNode* previous=nextPartHead;

            while(nodesToReverse--)
            {
                ListNode* nextNode=current->next;

                current->next=previous;

                previous=current;

                current=nextNode;
            }

            return previous;
        }

        // Case 2 : Reverse starts after head
        else
        {
            int originalLeft=left;
            int originalRight=right;

            int moveSteps=left-2;

            // Last node of first part
            ListNode* firstPartLastNode=head;

            while(moveSteps--)
            {
                firstPartLastNode=firstPartLastNode->next;
            }

            // First node of last part
            ListNode* lastPartFirstNode=head;

            while(right--)
            {
                lastPartFirstNode=lastPartFirstNode->next;
            }

            ListNode* previous=lastPartFirstNode;

            ListNode* current=firstPartLastNode->next;

            int nodesToReverse=originalRight-originalLeft+1;

            while(nodesToReverse--)
            {
                ListNode* nextNode=current->next;

                current->next=previous;

                previous=current;

                current=nextNode;
            }

            firstPartLastNode->next=previous;

            return head;
        }
    }
};