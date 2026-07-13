// Approach
// 1. Do pointers use karaange:
//    slow te fast.
// 2. Dono pointers head ton start karaange.
// 3. Slow pointer ik step move karega,
//    jadki fast pointer do steps move karega.
// 4. Je linked list ch cycle hovegi,
//    ta fast pointer eventually
//    slow pointer nu catch kar lavega.
// 5. Je dono pointers kise vi node te mil jaan,
//    ta cycle present hai,
//    is karke true return karaange.
// 6. Je fast pointer
//    ya fast->next NULL ho jaave,
//    ta list end tak pahunch gayi,
//    matlab cycle nahi hai.
// 7. Is case ch false return karaange.

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return false;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;

            fast=fast->next->next;

            if(slow==fast)
            {
                return true;
            }
        }

        return false;
    }
};