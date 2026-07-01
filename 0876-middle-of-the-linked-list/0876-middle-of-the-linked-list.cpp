// Approach
// 1. Pehlaa check kraange je list empty aa ya sirf ik node aa,
//    ta sidha head return kr devaange.
// 2. Hun do pointers rakhange:
//    slow ik step chalega te fast do steps.
// 3. Jadon fast do steps chal reha hovega,
//    slow sirf ik step chalega.
// 4. Jadon fast list de end te pahunch jaave,
//    slow automatically middle node te hovega.
// 5. Je nodes even hon,
//    ta question according second middle node return krna aa.
// 6. Last ch slow return kr devaange.

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL&&fast->next!=NULL)
        {
            // Slow moves one step, fast moves two steps
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};