// Approach
// 1. Pehlaa check kraange je list empty aa ya sirf ik node aa,
//    ta cycle possible nhi aa, false return kr devaange.
// 2. Hun do pointers rakhange:
//    slow ik step chalega te fast do steps.
// 3. Je list ch cycle hovegi,
//    ta fast pointer ik time baad slow pointer nu catch kr laega.
// 4. Je dono pointers kise node te mil jaan,
//    matlab cycle exist krdi aa.
// 5. Je fast ya fast->next NULL ho jaave,
//    matlab list end te pahunch gayi te cycle nhi aa.
// 6. Accordingly true ya false return kr devaange.

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return false;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL&&fast->next!=NULL)
        {
            // Slow moves one step, fast moves two steps
            slow=slow->next;
            fast=fast->next->next;

            // If both pointers meet, cycle exists
            if(slow==fast)
            {
                return true;
            }
        }

        return false;
    }
};